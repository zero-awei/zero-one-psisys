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
#include "PurComFindBillMapper.h"
#include "PurComFindDetailBillMapper.h"
#include "PurComDetailsMapper.h"
#include "PurComListMapper.h"
#include "PurComDividedListMapper.h"
#include "PurCandidateQuotMapper.h"
#include <sstream>


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
	if (obj.getIsEffective()==u8"是") sql << " AND `is_effective` = 1 "; \
	else sql << " AND `is_effective`= 0 ";\
}\
if (!obj.getIsClosed().empty()) {\
	if (obj.getIsClosed() == u8"是") sql << " AND `is_closed`= 1 "; \
	else sql << " AND `is_closed`= 0 "; \
}\
if (!obj.getIsVoided().empty()) {\
	if (obj.getIsVoided() == u8"是") sql << " AND `is_voided`= 1 "; \
	else sql << " AND `is_voided`= 0 "; \
}


uint64_t PurCompareDAO::count(const PurCompareDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_compare";
	PURCOMPARE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<PurCompareDO> PurCompareDAO::selectPurComFindBill(const PurCompareDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT @rowNum:=@rowNum+1 as id,bill_no,bill_date,subject,src_no,payment_method,delivery_time,bill_stage,\
		is_effective,is_closed,is_voided,delivery_place,remark,is_auto,is_rubric,effective_time,\
		approver,create_time,create_by,sys_org_code,update_time,update_by FROM pur_compare,(SELECT (@rowNum:=0)) b";
	PURCOMPARE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurComFindBillMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurCompareDO, PurComFindBillMapper>(sqlStr, mapper, params);
}

std::list<PurCompareDO> PurCompareDAO::selectPurComFindDetailBill(const PurCompareDO& obj)
{
	string sql;
	sql = "SELECT bill_no,bill_date,bill_stage,is_effective,is_closed,is_voided,\
		effective_time,approver,bpmi_instance_id,create_time,sys_org_code,create_by,update_time,\
		update_by,is_auto,is_rubric,src_bill_type,subject,src_no,payment_method,delivery_time,\
		delivery_place,remark,approval_remark,approval_result_type \
		FROM pur_compare \
		WHERE `bill_no`=?";
	//sql中待补attachment
	PurComFindDetailBillMapper mapper;
	return sqlSession->executeQuery<PurCompareDO, PurComFindDetailBillMapper>(sql, mapper, "%s", obj.getBillNo());
}

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
// 查询报价单列表
std::list<PurComQuotDO> PurCompareDAO::selectPurComList(const PurCompareDO& obj)
{
	string sql;
	sql = "SELECT bill_no,bill_date,subject,supplier_name,payment_method,\
		delivery_time,delivery_place,remark \
		FROM pur_quot \
		WHERE FIND_IN_SET(id,?)";
	PurComListMapper mapper;
	return sqlSession->executeQuery<PurComQuotDO, PurComListMapper>(sql, mapper, "%s" , obj.getCandidateQuotIds());
}
// 查询报价单分录列表
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
	// 通过报价单编号找分录
	return sqlSession->executeQuery< PurComQuotEntryDO, PurComDividedListMapper>(sql, mapper,"%s",obj.getBillNo());
}

uint64_t PurCompareDAO::insertPurCom(const AddPurComDO& iObj)
{
	string sql = "INSERT INTO `pur_compare` (id, bill_no, bill_date, is_effective, is_closed, is_voided, effective_time, approver, "
		"create_time, sys_org_code, create_by, update_time, update_by, is_auto, is_rubric, "
		"src_bill_type, subject, bill_stage, payment_method, delivery_time, delivery_place, remark) "
		"VALUES (?,?,?,?,?,?,?,?,NOW(),?,?,?,?,?,?,?,?,?,?,?,?,?)";
	// 删去了inqueryBill，找不到对应字段
	return sqlSession->executeUpdate(sql, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getId(), iObj.getBillId(), iObj.getBillDate(), iObj.getIsEffect(), iObj.getIsClose(), iObj.getIsCancelled(), iObj.getEffectDate(),
		iObj.getApprover(), iObj.getMakeBillDept(), iObj.getMakeBillPerson(), iObj.getUdpateDate(), iObj.getUdpatePerson(), iObj.getAutoBill(),
		iObj.getRedBill(), iObj.getBillType(), iObj.getBillTheme(), iObj.getBillStatus(), iObj.getPayMethod(),
		iObj.getDeliveryDate(), iObj.getDeliveryPlace(), iObj.getRemark());
}

int PurCompareDAO::updatePurCom(const ModPurComDO& uObj)
{
	string sql = "UPDATE `pur_compare` SET bill_date=?, is_effective=?, is_closed=?, is_voided=?, effective_time=?, approver=?, "
		"create_time=?, sys_org_code=?, create_by=?, update_time=NOW(), update_by=?, is_auto=?, is_rubric=?, "
		"src_bill_type=?, subject=?, bill_stage=?, payment_method=?, delivery_time=?, delivery_place=?, "
		"remark=?, approval_result_type=?, approval_remark=? WHERE bill_no=?";
	// 删去了inqueryBill，找不到对应字段

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		uObj.getBillDate(), uObj.getIsEffect(), uObj.getIsClose(), uObj.getIsCancelled(), uObj.getEffectDate(),
		uObj.getApprover(), uObj.getMakeBillDate(), uObj.getMakeBillDept(), uObj.getMakeBillPerson(),
		uObj.getUdpatePerson(), uObj.getAutoBill(), uObj.getRedBill(), uObj.getBillType(), uObj.getBillTheme(), uObj.getBillStatus(),
		uObj.getPayMethod(), uObj.getDeliveryDate(), uObj.getDeliveryPlace(), uObj.getRemark(), uObj.getAuditResult(), uObj.getAuditRemark(),
		uObj.getBillId());
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