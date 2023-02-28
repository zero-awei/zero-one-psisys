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
if (!obj.getBill_no_list().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", list<std::string>, obj.getBill_no_list()); \
} 


// 统计数据条数
uint64_t PurInquiryDAO::count(const PurInquiryDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_inquiry";
	PUR_INQUIRY_TERAM_PARSE(iObj, sql);
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


// 导出询价单
list<PurInquiryDO> PurInquiryDAO::selectPurInquiryExport(const string& bill_no) //const PurInquiryDO& obj
{
	string sql = "SELECT id,bill_no,bill_date,bill_stage,subject,src_no,src_bill_id,src_bill_type,payment_method,\
				  delivery_place, delivery_time,contact, phone, fax, email, qty, amt, quot_count, remark,\
				  is_effective, effective_time, is_closed, is_voided, is_auto, is_rubric, create_by, create_time, \
				  sys_org_code, update_by,  attachment, bpmi_instance_id, approver,approval_result_type, approval_remark\
				  FROM pur_inquiry WHERE `bill_no`=?";
	PurInquiryExportMapper mapper;
	return sqlSession->executeQuery<PurInquiryDO, PurInquiryExportMapper>(sql, mapper, "%s", bill_no);
}


// 导出询价单对应明细
list<PurInquiryEntryDO>  PurInquiryDAO::selectPurInquiryExportEntry(const string& bill_no)
{
	string sql = "SELECT  bill_no, entry_no,src_entry_id,src_no,src_bill_id,src_bill_type,material_id,unit_id,\
				  qty,tax_rate,price,amt,custom1,custom2,remark \
				  FROM pur_inquiry_entry as pie WHERE `bill_no`=?";
	PurInquiryExportEntryMapper mapper;
	return sqlSession->executeQuery<PurInquiryEntryDO, PurInquiryExportEntryMapper>(sql, mapper, "%s", bill_no);
}


// 导入pur_inquiry
uint64_t PurInquiryDAO::input(const PurInquiryDO& obj)
{
	string sql = "INSERT INTO `pur_inquiry` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	if (obj.getEffective_time() != "") {
		sql += ", '" + obj.getEffective_time() + "'";
	}
	else {
		sql += ", null";
	}
	sql += ", ?, ?, ?, ?, ?, ?";
	if (obj.getUpdate_time() != "") {
		sql += ", '" + obj.getUpdate_time() + "'";
	}
	else {
		sql += ", null";
	}
	if (obj.getVersion() != -1) {
		sql += ", " + to_string(obj.getVersion());
	}
	else {
		sql += ", null";
	}
	sql += ")";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%s%s%s%d%d%i%s%s%i%s%s%s%s%s%i%i%i%s%s%s%s",
		obj.getId(), obj.getBill_no(), obj.getBill_date(), obj.getSrc_bill_type(), obj.getSrc_bill_id(),obj.getSrc_no(), obj.getSubject(), 
		obj.getIs_rubric(), obj.getPayment_method(), obj.getDelivery_place(),obj.getDelivery_time(), obj.getContact(), obj.getPhone(),\
		obj.getFax(), obj.getEmail(),obj.getQty(),obj.getAmt(), obj.getQuot_count(), obj.getAttachment(), obj.getRemark(),\
		obj.getIs_auto(),obj.getBill_stage(), obj.getApprover(), obj.getBpmi_instance_id(), obj.getApproval_result_type(),\
		obj.getApproval_remark(),obj.getIs_effective(),	obj.getIs_closed(), obj.getIs_voided(),	obj.getSys_org_code(), \
		obj.getCreate_by(),obj.getCreate_time(), obj.getUpdate_by());
}

// 导入明细 pur_inquiry_entry
uint64_t PurInquiryDAO::inputEntry(const PurInquiryEntryDO& obj)
{
	string sql = "INSERT INTO `pur_inquiry_entry` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	if (obj.getEntry_version() != 1) {
		sql += ", " + to_string(obj.getEntry_version());
	}
	else {
		sql += ", null";
	}
	sql += ")";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%d%d%d%d%s%s%s",
		obj.getEntry_id(),obj.getMid(),obj.getEntry_bill_no(),obj.getEntry_no(),obj.getEntry_src_bill_type(),
		obj.getEntry_src_bill_id(), obj.getSrc_entry_id(), obj.getEntry_src_no(), obj.getMaterial_id(),obj.getUnit_id(),
		obj.getEntry_qty(),obj.getTax_rate(),obj.getPrice(), obj.getEntry_Amt(), obj.getEntry_remark(),obj.getCustom1(),obj.getCustom2());
}


uint64_t PurInquiryDAO::insert(const AddPurInquiryDO& iObj)
{// 
	string sql = "INSERT INTO `pur_inquiry` (create_by,create_time,sys_org_code,`id`,`bill_no`, `subject`, \
    `payment_method`,contact,phone,fax,email,remark,is_rubric \
	,is_auto,effective_time,bill_stage,bill_date,delivery_place) VALUES (?, \
	?, ?,?, ?, ?,?, ?, ?,?, ?, ?,?, ?, ?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%i%i%s%s%s%s", iObj.getCreate_by(), \
		iObj.getCreate_time(), iObj.getSys_org_code(), iObj.getId(), \
		iObj.getBill_no(), iObj.getSubject(), iObj.getPayment_method(), \
		iObj.getContact(), iObj.getPhone(), iObj.getFax(), iObj.getEmail(), iObj.getRemark(), \
		iObj.getIs_rubric(), iObj.getIs_auto(), \
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
	string sql = "UPDATE `pur_inquiry` SET `subject`=?,update_by=?,update_time=?, approval_result_type=?,approval_remark=?,\
    `payment_method`=?,contact=?,phone=?,fax=?,email=?,remark=? ,approver=?\
	,bill_date=?,delivery_place=? WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", \
		iObj.getSubject(), iObj.getUpdate_by(), iObj.getupdate_time(), \
		iObj.getApproval_result_type(), iObj.getApproval_remark(), iObj.getPayment_method(), iObj.getContact(), \
		iObj.getPhone(), iObj.getFax(), iObj.getEmail(), iObj.getRemark(), iObj.getApprover(), \
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