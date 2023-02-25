/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/18 22:46

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
#include "PurInquiryDAO.h"
#include "PurInquiryMapper.h"
#include <sstream>



//定义条件解析宏，减少重复代码
#define PUR_INQUIRY_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getSubject().empty()) { \
	sql << " AND `subject`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (obj.getIs_effective() != -1) { \
	sql << " AND `is_effective`=? ";\
	SQLPARAMS_PUSH(params, "i",  int, obj.getIs_effective()); \
} \
if (obj.getIs_closed() != -1) { \
	sql << " AND `is_closed`=? "; \
	SQLPARAMS_PUSH(params, "i",  int, obj.getIs_closed()); \
} \
if (obj.getIs_voided() != -1) { \
	sql << " AND `is_voided`=? "; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided()); \
} 

//定义条件解析宏，减少重复代码
#define PUR_INQUIRY_EXPORT_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} 


// 定义条件解析宏，减少重复代码
#define PUR_INQUIRY_INTO_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND bill_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} 
//if (!obj.getBill_date().empty()) { \
//	sql << " AND bill_date=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
//} \
//if (!obj.getSrc_bill_type().empty()) { \
//	sql << " AND src_bill_type=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_bill_type()); \
//}\
//if (!obj.getSrc_bill_id().empty()) { \
//	sql << " AND src_bill_id=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_bill_id()); \
//} \
//if (!obj.getSrc_no().empty()) { \
//	sql << " AND src_no=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_no()); \
//} \
//if (!obj.getSubject().empty()) { \
//	sql << " AND subject=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
//} \
//if (!obj.getDelivery_time().empty()) { \
//	sql << " AND delivery_time=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getDelivery_time()); \
//} \
//if (obj.getIs_rubric() != -1) { \
//	sql << " AND is_rubric=?"; \
//	SQLPARAMS_PUSH(params, "i", int, obj.getIs_rubric()); \
//} \
//if (!obj.getPayment_method().empty()) { \
//	sql << " AND payment_method=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getPayment_method()); \
//} \
//if (!obj.getDelivery_place().empty()) { \
//	sql << " AND delivery_place=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getDelivery_place()); \
//} \
//if (!obj.getDelivery_time().empty()) { \
//	sql << " AND delivery_time=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getDelivery_time()); \
//} \
//if (!obj.getContact().empty()) { \
//	sql << " AND contact=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getContact()); \
//} \
//if (!obj.getPhone().empty()) { \
//	sql << " AND phone=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getPhone()); \
//} \
//if (!obj.getFax().empty()) { \
//	sql << " AND fax=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getFax()); \
//} \
//if (!obj.getEmail().empty()) { \
//	sql << " AND email=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getEmail()); \
//} \
//if (obj.getQty() != -1) { \
//	sql << " AND qty=?"; \
//	SQLPARAMS_PUSH(params, "d", double, obj.getQty()); \
//} \
//if (obj.getAmt() != -1) { \
//	sql << " AND amt=?"; \
//	SQLPARAMS_PUSH(params, "d", double, obj.getAmt()); \
//} \
//if (obj.getQuot_count() != -1) { \
//	sql << " AND quot_count=?"; \
//	SQLPARAMS_PUSH(params, "i", int, obj.getQuot_count()); \
//} \
//if (!obj.getAttachment().empty()) { \
//	sql << " AND attachment=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getAttachment()); \
//} \
//if (!obj.getRemark().empty()) { \
//	sql << " AND remark=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, obj.getRemark()); \
//} \
//if (obj.getIs_auto() != -1) { \
//	sql << " AND is_auto=?"; \
//	SQLPARAMS_PUSH(params, "i", int, obj.getIs_auto()); \
//} \
//if (!obj.getBill_stage().empty()) { \
//	sql << " AND bill_stage=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getBill_stage()); \
//} \
//if (!obj.getApprover().empty()) { \
//	sql << " AND approver=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getApprover()); \
//} \
//if (!obj.getBpmi_instance_id().empty()) { \
//	sql << " AND bpmi_instance_id=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getBpmi_instance_id()); \
//} \
//if (!obj.getApproval_result_type().empty()) { \
//	sql << " AND approval_result_type=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getApproval_result_type()); \
//} \
//if (!obj.getApproval_remark().empty()) { \
//	sql << " AND approval_remark=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getApproval_remark()); \
//} \
//if (obj.getIs_effective() != -1) { \
//	sql << " AND is_effective=?"; \
//	SQLPARAMS_PUSH(params, "i", int, obj.getIs_effective()); \
//} \
//if (!obj.getEffective_time().empty()) { \
//	sql << " AND effective_time=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getEffective_time()); \
//} \
//if (obj.getIs_closed() != -1) { \
//	sql << " AND is_closed=?"; \
//	SQLPARAMS_PUSH(params, "i", int, obj.getIs_closed()); \
//} \
//if (obj.getIs_voided() != -1) { \
//	sql << " AND is_voided=?"; \
//	SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided()); \
//} \
//if (!obj.getSys_org_code().empty()) { \
//	sql << " AND sys_org_code=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getSys_org_code()); \
//} \
//if (!obj.getCreate_by().empty()) { \
//	sql << " AND create_by=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getCreate_by()); \
//} \
//if (!obj.getCreate_time().empty()) { \
//	sql << " AND create_time=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getCreate_time()); \
// } \
//if (!obj.getUpdate_by().empty()) { \
//	sql << " AND update_by=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getUpdate_by()); \
//} \
//if (!obj.getUpdate_time().empty()) { \
//	sql << " AND update_time=?"; \
//	SQLPARAMS_PUSH(params, "s",  std::string, obj.getUpdate_time()); \
//}


// 统计数据条数
uint64_t PurInquiryDAO::count(const PurInquiryDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_inquiry";
	PUR_INQUIRY_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 统计导出的数据条数
uint64_t PurInquiryDAO::countExport(PurInquiryDO iObj)
{
	stringstream sql;

	// 暂时用于测试（要修改！！！！！！！！！！！！！！！！！！！！！）
	sql << "SELECT COUNT(*) FROM pur_inquiry";
	PUR_INQUIRY_EXPORT_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 统计导入的数据条数
uint64_t PurInquiryDAO::countInto(PurInquiryDO iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_inquiry";
	PUR_INQUIRY_INTO_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}



// 分页查询询价单列表
list<PurInquiryDO> PurInquiryDAO::selectPurInquiryFindBillWithPage(const PurInquiryDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT bill_no, bill_date,src_bill_type,src_bill_id,src_no, subject,is_rubric,\
			payment_method, delivery_place,delivery_time,contact,phone, fax, email,qty,amt, quot_count,\
		    attachment, remark,is_auto,bill_stage,approver,bpmi_instance_id,approval_result_type,\
			approval_remark, is_effective,effective_time, is_closed,is_voided,sys_org_code,create_by,create_time,\
			update_by,update_time,version FROM pur_inquiry ";
	PUR_INQUIRY_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurInquiryFindBillMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurInquiryDO, PurInquiryFindBillMapper>(sqlStr, mapper, params);
}

//按指定单据编号查询询价单详情
list<PurInquiryDO> PurInquiryDAO::selectPurInquiryFindDetailBill(const PurInquiryDO& obj)
{
	string sql = "SELECT bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided,\
		subject, payment_method, delivery_place, contact, phone, fax, email, quot_count,\
		remark, approval_remark,attachment, approval_result_type \
		FROM pur_inquiry p join pur_inquiry_entry pe on p.bill_no=pe.bill_no \
		WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PurInquiryFindDetailBillMapper mapper;
	return sqlSession->executeQuery<PurInquiryDO, PurInquiryFindDetailBillMapper>(sql, mapper, "%s", obj.getBill_no());
}


// 指定询价单对应明细
list<PurInquiryEntryDO>  PurInquiryDAO::selectPurInquiryFindDetailBillEntry(const PurInquiryEntryDO& obj)
{
	string sql;
	sql = "SELECT src_bill_type, src_no,material_id,unit_id,qty,tax_rate,price,amt,remark,custom1,custom2\
		   FROM pur_inquiry_entry as pie\
		   WHERE `bill_no`=?";
	PurInquiryEntryMapper mapper;
	return sqlSession->executeQuery<PurInquiryEntryDO, PurInquiryEntryMapper>(sql, mapper, "%s", obj.getEntry_bill_no());
}

// 导出
list<PurInquiryDO> PurInquiryDAO::selectPurInquiryExport(const PurInquiryDO& obj, long pageIndex, long pageSize)
{
	stringstream sql;
	sql << "SELECT id,payment_method, delivery_place, delivery_time,contact, phone, fax, email,\
				qty, amt, quot_count, is_effective, attachment, src_bill_id, subject, bill_stage, src_no,\
				is_auto, remark, bpmi_instance_id, is_voided, bill_no, is_rubric, src_bill_type, create_time,\
				effective_time, approver, update_by, sys_org_code, is_closed, approval_result_type, bill_date, create_by, approval_remark\
				FROM pur_inquiry WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PUR_INQUIRY_EXPORT_TERAM_PARSE(obj, sql);
	//sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurInquiryExportMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurInquiryDO, PurInquiryExportMapper>(sqlStr, mapper,params);
}

// 导出对应明细
list<PurInquiryEntryDO>  PurInquiryDAO::selectPurInquiryExportEntry(const PurInquiryEntryDO& obj)
{
	string sql;
	sql = "SELECT material_id,unit_id,qty,price,amt,custom1,src_no,entry_no,custom2,src_bill_id,src_bill_type,\
		   remark, bill_no, src_bill_id	FROM pur_inquiry_entry as pie WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PurInquiryExportEntryMapper mapper;
	return sqlSession->executeQuery<PurInquiryEntryDO, PurInquiryExportEntryMapper>(sql, mapper, "%s", obj.getEntry_bill_no());
}



uint64_t PurInquiryDAO::insert(const AddPurInquiryDO& iObj)
{// 
	string sql = "INSERT INTO `pur_inquiry` ( `id`,`bill_no`, `subject`, \
    `payment_method`,contact,phone,fax,email,remark,is_rubric \
	,is_auto,create_time,update_by,effective_time,bill_stage,bill_date,delivery_place) VALUES (?, \
	?, ?,?, ?, ?,?, ?, ?,?, ?, ?,?, ?, ?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%i%i%s%s%s%s%s%s", iObj.getId(), \
		iObj.getBill_no(), iObj.getSubject(), iObj.getPayment_method(), \
		iObj.getContact(), iObj.getPhone(), iObj.getFax(), iObj.getEmail(), iObj.getRemark(), \
		iObj.getIs_rubric(), iObj.getIs_auto(), iObj.getCreate_time(), iObj.getUpdate_by(), \
		iObj.getEffective_time(), iObj.getBill_stage(), iObj.getBill_Date(), iObj.getDelivery_place());
}

uint64_t PurInquiryDAO::insertByEntry(const AddPurInquiryEntryDO& iObj)
{
	//
	string sql = "INSERT INTO `pur_inquiry_entry` (bill_no,entry_no,mid,id,src_bill_type,src_no,material_id,unit_id,qty ,\
		tax_rate,price,amt,remark,custom1,custom2) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%i%s%s%s%s%s%s%i%i%i%i%s%s%s", iObj.getBill_no(), iObj.getEntry_no(), iObj.getMid(), iObj.getId(), iObj.getSrc_bill_type(), \
		iObj.getSrc_no(), iObj.getMaterial_id(), iObj.getUnit_id(), iObj.getQty(), iObj.getTax_rate(), iObj.getPrice(), \
		iObj.getAmt(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2());
}

int PurInquiryDAO::update(const AddPurInquiryDO& iObj)
{
	string sql = "UPDATE `pur_inquiry` SET `subject`=?, \
    `payment_method`=?,contact=?,phone=?,fax=?,email=?,remark=? \
	,bill_date=?,delivery_place=? WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s", \
		iObj.getSubject(), iObj.getPayment_method(), iObj.getContact(), \
		iObj.getPhone(), iObj.getFax(), iObj.getEmail(), iObj.getRemark(), \
		iObj.getBill_Date(), iObj.getDelivery_place(), iObj.getBill_no());
}

int PurInquiryDAO::updateByEntry(const AddPurInquiryEntryDO& iObj)
{
	/*string sql = "UPDATE `pur_inquiry_entry` SET entry_no=?,mid=?,src_bill_type=?,src_no=?,material_id=?,unit_id=?,qty=? ,\
		tax_rate=?,price=?,amt=?,remark=?,custom1=?,custom2=? WHERE id=?";
	return sqlSession->executeUpdate(sql, "%i%s%s%s%s%s%i%i%i%i%s%s%s%s", iObj.getEntry_no(), iObj.getMid(), iObj.getSrc_bill_type(), \
		iObj.getSrc_no(), iObj.getMaterial_id(), iObj.getUnit_id(), iObj.getQty(), iObj.getTax_rate(), iObj.getPrice(), \
		iObj.getAmt(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2(), iObj.getId());*/


	string sql = "DELETE FROM pur_inquiry_entry WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%s", iObj.getBill_no());
}

int PurInquiryDAO::deleteById(string bill_no)
{
	string sql = "DELETE FROM pur_inquiry_entry WHERE bill_no=?";
	sqlSession->executeUpdate(sql, "%s", bill_no);

	sql = "DELETE FROM pur_inquiry WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%s", bill_no);
}

int PurInquiryDAO::updateByModBillStatus(const PurInquiryModBillStatusDO& uObj)
{
	string sql = "UPDATE pur_inquiry SET is_closed=?,is_voided=? WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%i%i%s", uObj.getIs_close(), uObj.getIs_voided(), uObj.getBill_no());
}