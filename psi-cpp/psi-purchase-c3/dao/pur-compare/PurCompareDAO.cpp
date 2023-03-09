/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:59:30

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "PurCompareDAO.h"
#include "PurComExportMapper.h"
#include "PurComEntryExportMapper.h"
#include "PurComFindBillMapper.h"
#include "PurComFindDetailBillMapper.h"
#include "PurComDetailsMapper.h"
#include "PurComListMapper.h"
#include "PurComDividedListMapper.h"
#include "PurCandidateQuotMapper.h"
#include <sstream>

#define WORDTOI(s) (s==CharsetConvertHepler::ansiToUtf8("是")? 1 : 0)
// 定义宏用于是否为空判断与类型转换
#define FROMSTRING(s) \
if (obj.get##s() != "") {\
sql += ", '" + obj.get##s() + "'";}\
else {sql += ", null";}
#define FROMSTRING_NOTNULL(s) \
if (obj.get##s() != "") {\
sql += ", '" + obj.get##s() + "'";}\
else {return 0;}
#define FROMNUMBER(s) \
if (obj.get##s() != -1) {\
sql += ", " + to_string(obj.get##s());}\
else {sql += ", null";}
#define FROMNUMBER_NOTNULL(s) \
if (obj.get##s() != -1) {\
sql += ", " + to_string(obj.get##s());}\
else {return 0;}
#define FROMNUMBER_DEFAULT(s,dstr) \
if (obj.get##s() != -1) {\
sql += ", " + to_string(obj.get##s());}\
else {sql+=","+dstr;}
//定义条件解析宏，减少重复代码
#define PURCOMPARE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBillNo().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo()); \
}\
if (!obj.getBillDateBegin().empty()) {\
	sql << " AND Date(`bill_date`)>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDateBegin()); \
}\
if (!obj.getBillDateEnd().empty()) {\
	sql << " AND Date(`bill_date`)<=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDateEnd()); \
}\
if (!obj.getSubject().empty()) {\
	sql << " AND `subject`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
}\
if (!obj.getBillStage().empty()) {\
	sql << " AND `bill_stage`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillStage()); \
}\
if (!obj.getIsEffective().empty()) {\
	if (WORDTOI(obj.getIsEffective())) sql << " AND `is_effective` = 1 "; \
	else sql << " AND `is_effective`= 0 ";\
}\
if (!obj.getIsClosed().empty()) {\
	if (WORDTOI(obj.getIsClosed()) ) sql << " AND `is_closed`= 1 "; \
	else sql << " AND `is_closed`= 0 "; \
}\
if (!obj.getIsVoided().empty()) {\
	if (WORDTOI(obj.getIsVoided())) sql << " AND `is_voided`= 1 "; \
	else sql << " AND `is_voided`= 0 "; \
}

// 统计数据条数
uint64_t PurCompareDAO::count(const PurCompareDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_compare";
	PURCOMPARE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// 分页查询比价单单据列表
std::list<PurCompareDO> PurCompareDAO::selectPurComFindBill(const PurCompareDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT @rowNum:=@rowNum+1 as id,bill_no,bill_date,subject,src_no,payment_method,delivery_time,bill_stage,\
		is_effective,is_closed,is_voided,delivery_place,remark,is_auto,is_rubric,effective_time,\
		approver,create_time,create_by,sys_org_code,update_time,update_by FROM pur_compare,(SELECT (@rowNum:=0)) b";
	PURCOMPARE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	string sqlStr = sql.str();
	PurComFindBillMapper mapper;
	return sqlSession->executeQuery<PurCompareDO, PurComFindBillMapper>(sqlStr, mapper, params);
}
// 查询指定比价单详细信息—比价单
std::list<PurCompareDO> PurCompareDAO::selectPurComFindDetailBill(const PurCompareDO& obj)
{
	string sql;
	sql = "SELECT bill_no,bill_date,bill_stage,is_effective,is_closed,is_voided,\
		effective_time,approver,bpmi_instance_id,create_time,sys_org_code,create_by,update_time,\
		update_by,is_auto,is_rubric,src_bill_type,subject,src_no,payment_method,delivery_time,\
		delivery_place,remark,approval_remark,approval_result_type,attachment \
		FROM pur_compare \
		WHERE `bill_no`=?";
	PurComFindDetailBillMapper mapper;
	return sqlSession->executeQuery<PurCompareDO, PurComFindDetailBillMapper>(sql, mapper, "%s", obj.getBillNo());
}
// 查询指定比价单详细信息—比价单明细
std::list<PurCompareEntryDO> PurCompareDAO::selectPurComFindDetailBillEntry(const PurCompareEntryDO& obj)
{
	string sql;
	sql = "SELECT entry_no,bs.name as supplier_name,src_no,bm.name as material_name,\
		model as specifications,bu.name as unit_name,qty,tax_rate,price,\
		discount_rate,amt,ranking,pce.remark,custom1,custom2 \
		FROM pur_compare_entry as pce \
		left outer join bas_material as bm on pce.material_id=bm.id\
		left outer join bas_supplier as bs on pce.supplier_id=bs.id\
		left outer join bas_unit as bu on pce.unit_id=bu.id\
		WHERE `bill_no`=?";
	PurComDetailsMapper mapper;
	return sqlSession->executeQuery<PurCompareEntryDO, PurComDetailsMapper>(sql, mapper, "%s", obj.getBillNo());
}

// 查询候选报价单
std::list<PurCompareDO> PurCompareDAO::selectCandidateQuot(const PurCompareDO& obj)
{
	string sql;
	sql = "SELECT candidate_quot_ids FROM  pur_compare WHERE bill_no=?";
	PurCandidateQuotMapper mapper;
	return sqlSession->executeQuery<PurCompareDO, PurCandidateQuotMapper>(sql, mapper, "%s", obj.getBillNo());
}
// 查询报价单
std::list<PurComQuotDO> PurCompareDAO::selectPurComList(const PurCompareDO& obj)
{
	string sql;
	sql = "SELECT bill_no,bill_date,subject,supplier_name,payment_method,\
		delivery_time,delivery_place,remark \
		FROM pur_quot \
		WHERE FIND_IN_SET(id,?)";
	PurComListMapper mapper;
	return sqlSession->executeQuery<PurComQuotDO, PurComListMapper>(sql, mapper, "%s", obj.getCandidateQuotIds());
}
// 查询报价单分录
std::list<PurComQuotEntryDO> PurCompareDAO::selectPurComDividedList(const PurComQuotEntryDO& obj)
{
	string sql;
	sql = "SELECT bill_no,entry_no,bm.name as material_name,bm.model as specifications,\
		bu.name as unit_name,qty,tax_rate,price,discount_rate,amt,pqe.remark,custom1,custom2 \
		FROM pur_quot_entry as pqe \
		left outer join bas_material as bm on pqe.material_id=bm.id\
		left outer join bas_unit as bu on pqe.unit_id=bu.id\
		WHERE `bill_no`=?";

	PurComDividedListMapper mapper;
	return sqlSession->executeQuery< PurComQuotEntryDO, PurComDividedListMapper>(sql, mapper, "%s", obj.getBillNo());
}

// 导出—查询比价单单据信息
std::list<PurCompareDO> PurCompareDAO::selectPurComExport(const PurCompareDO& obj, bool lsAll)
{
	string sql;
	// 不输入单据号则导出全部，否则按照给定单据号导出
	if (lsAll)
	{
		sql = "SELECT bill_no,bill_date,bill_stage,is_effective,is_closed,is_voided,\
		effective_time,approver,bpmi_instance_id,create_time,sys_org_code,create_by,update_time,\
		update_by,is_auto,is_rubric,src_bill_type,subject,src_no,payment_method,delivery_time,\
		delivery_place,remark,approval_remark,approval_result_type,attachment,src_bill_id,candidate_quot_ids \
		FROM pur_compare";
		PurComExportMapper mapper;
		return sqlSession->executeQuery<PurCompareDO, PurComExportMapper>(sql, mapper);
	}
	else
	{
		sql = "SELECT bill_no,bill_date,bill_stage,is_effective,is_closed,is_voided,\
		effective_time,approver,bpmi_instance_id,create_time,sys_org_code,create_by,update_time,\
		update_by,is_auto,is_rubric,src_bill_type,subject,src_no,payment_method,delivery_time,\
		delivery_place,remark,approval_remark,approval_result_type,attachment,src_bill_id,candidate_quot_ids \
		FROM pur_compare \
		WHERE `bill_no`=?";
		PurComExportMapper mapper;
		return sqlSession->executeQuery<PurCompareDO, PurComExportMapper>(sql, mapper, "%s", obj.getBillNo());
	}
}
// 导出—查询比价单分录单据信息
std::list<PurCompareEntryDO> PurCompareDAO::selectPurComEntryExport(const PurCompareEntryDO& obj, bool lsAll)
{
	string sql;
	// 不输入单据号则导出全部，否则按照给定单据号导出
	if (lsAll)
	{
		sql = "SELECT entry_no,bs.name as supplier_name,src_no,bm.name as material_name,\
		model as specifications,bu.name as unit_name,qty,tax_rate,price,\
		discount_rate,amt,ranking,pce.remark,custom1,custom2,bill_no,src_bill_type,src_bill_id,src_entry_id \
		FROM pur_compare_entry as pce \
		left outer join bas_material as bm on pce.material_id=bm.id\
		left outer join bas_supplier as bs on pce.supplier_id=bs.id\
		left outer join bas_unit as bu on pce.unit_id=bu.id";
		PurComEntryExportMapper mapper;
		return sqlSession->executeQuery<PurCompareEntryDO, PurComEntryExportMapper>(sql, mapper);
	}
	sql = "SELECT entry_no,bs.name as supplier_name,src_no,bm.name as material_name,\
		model as specifications,bu.name as unit_name,qty,tax_rate,price,\
		discount_rate,amt,ranking,pce.remark,custom1,custom2,bill_no,src_bill_type,src_bill_id,src_entry_id \
		FROM pur_compare_entry as pce \
		left outer join bas_material as bm on pce.material_id=bm.id\
		left outer join bas_supplier as bs on pce.supplier_id=bs.id\
		left outer join bas_unit as bu on pce.unit_id=bu.id\
		WHERE `bill_no`=?";
	PurComEntryExportMapper mapper;
	return sqlSession->executeQuery<PurCompareEntryDO, PurComEntryExportMapper>(sql, mapper, "%s", obj.getBillNo());
}
// 导入—插入比价单单据信息
uint64_t PurCompareDAO::insertPurCom(const PurCompareDO& obj)
{
	string sql = "INSERT INTO `pur_compare` (id,bill_no,bill_date,src_bill_type,src_bill_id,src_no,subject,\
		is_rubric,candidate_quot_ids,payment_method,delivery_place,delivery_time,attachment,remark,is_auto,\
		bill_stage,approver,bpmi_instance_id,approval_result_type,approval_remark,is_effective,effective_time,\
		is_closed,is_voided,sys_org_code,create_by,create_time,update_by,update_time)\
		VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	FROMSTRING(DeliveryTime);
	sql += ", ?, ?, ?, ?, ?, ?, ?, ?, ?";
	FROMSTRING(EffectiveTime);
	sql += ", ?, ?, ?, ?";
	FROMSTRING(CreateTime);
	sql += ",?";
	FROMSTRING(UpdateTime);
	sql += ")";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%s%i%s%s%s%s%s%i%i%i%s%s%s",
		obj.getId(), obj.getBillNo(), obj.getBillDate(), obj.getSrcBillType(), obj.getSrcBillId(), obj.getSrcNo(),
		obj.getSubject(), WORDTOI(obj.getIsRubric()), obj.getCandidateQuotIds(), obj.getPaymentMethod(),
		obj.getDeliveryPlace(), /*obj.getDeliveryTime(), */obj.getAttachment(), obj.getRemark(), WORDTOI(obj.getIsAuto()),
		obj.getBillStage(), obj.getApprover(), obj.getBpmiInstanceId(), obj.getApprovalResultType(),
		obj.getApprovalRemark(), WORDTOI(obj.getIsEffective()), /*obj.getEffectiveTime(), */WORDTOI(obj.getIsClosed()),
		WORDTOI(obj.getIsVoided()), obj.getSysOrgCode(), obj.getCreateBy(), /*obj.getCreateTime(),*/obj.getUpdateBy()
	/*, obj.getUpdateTime()*/);
}
// 导入—插入比价单分录单据信息
uint64_t PurCompareDAO::insertPurComEntry(const PurCompareEntryDO& obj)
{
	// todo:将material等Name转为id
	// todo:部分not null字段是否传值检验	
	string sql = "INSERT INTO `pur_compare_entry` (id,mid,bill_no,entry_no,src_bill_type,src_bill_id,src_entry_id,\
		src_no,supplier_id,material_id,unit_id,qty,tax_rate,price,discount_rate,amt,ranking,remark,custom1,custom2)\
		VALUES (?, ?, ?, ?";
	FROMSTRING(SrcBillType);
	FROMSTRING(SrcBillId);
	FROMSTRING(SrcEntryId);
	FROMSTRING(SrcNo);
	FROMSTRING_NOTNULL(SupplierName);
	FROMSTRING_NOTNULL(MaterialName);
	FROMSTRING_NOTNULL(UnitName);
	FROMNUMBER_NOTNULL(Qty);
	FROMNUMBER_NOTNULL(TaxRate);
	FROMNUMBER_NOTNULL(Price);
	string dStr = "100.0000"; FROMNUMBER_DEFAULT(DiscountRate, dStr);
	FROMNUMBER_NOTNULL(Amt);
	dStr = "999";  FROMNUMBER_DEFAULT(Ranking, dStr);
	FROMSTRING(Remark);
	FROMSTRING(Custom1);
	FROMSTRING(Custom2);
	sql += ")";
	return sqlSession->executeInsert(sql, "%s%s%s%ll",
		obj.getId(), obj.getMid(), obj.getBillNo(), obj.getEntryNo());
}



uint64_t PurCompareDAO::insertPurCom(const AddPurComDO& iObj)
{
	// 录入明细数据
	for (PurComDetailDTO AddDetail : iObj.getDetail())
	{
		string sqlEntry = "INSERT INTO `pur_compare_entry` (`id`, mid, bill_no, entry_no, src_bill_type, "
			"src_bill_id, src_entry_id, src_no, supplier_id, material_id, unit_id, qty, tax_rate, price, "
			"discount_rate, amt, ranking, remark, custom1, custom2, version) "
			"VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

		sqlSession->executeUpdate(sqlEntry, "%s%s%s%i%s%s%s%s%s%s%s%d%d%d%d%d%i%s%s%s%d",
			AddDetail.getId(), AddDetail.getMid(), AddDetail.getBill_no(), AddDetail.getEntry_no(), AddDetail.getSrc_bill_type(),
			AddDetail.getSrc_bill_id(), AddDetail.getSrc_entry_id(), AddDetail.getSrc_no(), AddDetail.getSupplier_id(), AddDetail.getMaterial_id(),
			AddDetail.getUnit_id(), AddDetail.getQty(), AddDetail.getTax_rate(), AddDetail.getPrice(), AddDetail.getDiscount_rate(),
			AddDetail.getAmt(), AddDetail.getRanking(), AddDetail.getRemark(), AddDetail.getCustom1(), AddDetail.getCustom2(),
			AddDetail.getVersion());
	}

	string sql = "INSERT INTO `pur_compare` (id, bill_no, bill_date, src_bill_type, src_bill_id, src_no, subject, "
		"is_rubric, candidate_quot_ids, payment_method, delivery_place, delivery_time, attachment, remark, "
		"is_auto, bill_stage, approver, bpmi_instance_id, approval_result_type, approval_remark, is_effective, "
		"effective_time, is_closed, is_voided, sys_org_code, create_by, create_time, update_by, "
		"update_time, version) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%s%s%i%s%s%s%s%s%i%s%i%i%s%s%s%s%s%i",
		iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSrcBillType(), iObj.getSrcBillType(),
		iObj.getSrcNo(), iObj.getSubject(), iObj.getIsRubric(), iObj.getCandidateQuotIds(), iObj.getPaymentMethod(),
		iObj.getDeliveryPlace(), iObj.getDeliveryTime(), iObj.getAttachment(), iObj.getRemark(), iObj.getIsAuto(),
		iObj.getBillStage(), iObj.getApprover(), iObj.getBpmiInstanceId(), iObj.getApprovalResultType(), iObj.getApprovalRemark(),
		iObj.getIsEffective(), iObj.getEffectiveTime(), iObj.getIsClosed(), iObj.getIsVoided(), iObj.getSysOrgCode(),
		iObj.getCreateBy(), iObj.getCreateTime(), iObj.getUpdateBy(), iObj.getUpdateTime(), iObj.getVersion());
}

int PurCompareDAO::updatePurCom(const ModPurComDO& uObj)
{
	// 录入明细数据
	for (PurComDetailDTO ModDetail : uObj.getDetail())
	{
		string sqlEntry = "UPDATE `pur_compare_entry` SET unit_id=?, ranking=?, remark=?, custom1=?, custom2=?, version=?"
			" WHERE bill_no=?";

		sqlSession->executeUpdate(sqlEntry, "%s%i%s%s%s%i%s",
			ModDetail.getUnit_id(), ModDetail.getRanking(), ModDetail.getRemark(), ModDetail.getCustom1(), ModDetail.getCustom2(),
			ModDetail.getVersion(), ModDetail.getBill_no());
	}

	string sql = "UPDATE `pur_compare` SET bill_date=?, src_bill_type=?, src_bill_id=?, src_no=?, subject=?, is_rubric=?, candidate_quot_ids=?, "
		"payment_method=?, delivery_place=?, delivery_time=?, attachment=?, remark=?, is_auto=?, bill_stage=?, "
		"approver=?, bpmi_instance_id=?, approval_result_type=?, approval_remark=?, is_effective=?, effective_time=?, is_closed=?, "
		"is_voided=?, update_by=?, update_time=?, version=? WHERE bill_no=?";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%s%s%s%s%s%s%i%s%s%s%s%s%i%s%i%i%s%s%i%s",
		uObj.getBillDate(), uObj.getSrcBillType(), uObj.getSrcBillId(), uObj.getSrcNo(), uObj.getSubject(),
		uObj.getIsRubric(), uObj.getCandidateQuotIds(), uObj.getPaymentMethod(), uObj.getDeliveryPlace(), uObj.getDeliveryTime(),
		uObj.getAttachment(), uObj.getRemark(), uObj.getIsAuto(), uObj.getBillStage(), uObj.getApprover(),
		uObj.getBpmiInstanceId(), uObj.getApprovalResultType(), uObj.getApprovalRemark(), uObj.getIsEffective(), uObj.getEffectiveTime(),
		uObj.getIsClosed(), uObj.getIsVoided(), uObj.getUpdateBy(), uObj.getUpdateTime(), uObj.getVersion(),
		uObj.getBillNo());
}

int PurCompareDAO::deletePurCom(const DelPurComDO& uObj)
{
	string sql = "DELETE FROM `pur_compare` WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getBillId());
}

int PurCompareDAO::updatePurComBillStatus(const ModPurComBillStatusDO& uObj)
{
	string sql = "UPDATE `pur_compare` SET is_effective=?, is_closed=?, is_voided=?, update_by=?, update_time=NOW() WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", uObj.getIsEffect(), uObj.getIsClose(), uObj.getIsCancelled(), uObj.getUpdatePerson(), uObj.getBillId());
}