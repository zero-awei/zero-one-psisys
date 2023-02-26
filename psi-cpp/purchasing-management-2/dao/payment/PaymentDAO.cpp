#include "stdafx.h"
#include "PaymentDAO.h"
#include "PaymentMapper.h"
#include <sstream>

//付款申请单-fin_payment_req

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getBill_date().empty()) { \
	sql << " AND bill_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
} \
if (obj.getAmt() != -1) { \
	sql << " AND amt=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getAmt()); \
} \

//修改单据状态
int PaymentDAO::ChangeStatusClose(const FinPayReqDO& uObj)
{
	string sql = "UPDATE `fin_payment_req` SET `is_closed`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s", uObj.getIs_closed(), uObj.getId());
}

int PaymentDAO::ChangeStatusCancel(const FinPayReqDO& uObj)
{
	string sql = "UPDATE `fin_payment_req` SET `is_voided`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s", uObj.getIs_voided(), uObj.getId());
}

// 删除申请单
int PaymentDAO::deleteById(const FinPayReqDO& uObj)
{
	string sql = "DELETE FROM `fin_payment_req` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}

// 添加申请(保存/提交) 插入总表数据
uint64_t PaymentDAO::insertPayment(const FinPayReqDO& obj)
{
	string sql = "INSERT INTO `fin_payment_req` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? ,? ,? ,?";
	if (obj.getEffective_time() != "") {
		sql += ", '" + obj.getEffective_time() + "'";
	}
	else {
		sql += ", null";
	}
	sql += ", ?, ?, ?, ?,? ,?";
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
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%d%d%s%s%i%s%s%s%s%s%i%i%i%s%s%s%s",
		obj.getId(), obj.getBill_no(), obj.getBill_date(), 
		obj.getSrc_bill_type(),obj.getSrc_bill_id(), obj.getSrc_no(), 
		obj.getSubject(),obj.getIs_rubric(), obj.getPayment_type(), 
		obj.getSupplier_id(),obj.getOp_dept(), obj.getOperator(), 
		obj.getAmt(),obj.getPaid_amt(), obj, obj.getAttachment(),
		obj.getRemark(), obj.getIs_auto(), obj.getBill_stage(),
		obj.getApprover(), obj.getBpmi_instance_id(), obj.getApproval_result_type(),
		obj.getApproval_remark(), obj.getIs_effective(),
		obj.getIs_closed(), obj.getIs_voided(), obj.getSys_org_code(),
		obj.getCreate_by(),obj.getCreate_time(), obj.getUpdate_by());
}