
#include "stdafx.h"
#include <sstream>
#include "PurPayReqDAO.h"
#include "purPayReqMapper.h"
#include "PurPayReqEntryMapper.h"
#include "PurPayReqFindBillMapper.h"
#include "PurPayReqFindDetailBillMapper.h"

#define PUR_PAY_REQ_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND bill_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getBill_date().empty()) { \
	sql << " AND bill_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
}\
if (!obj.getSubject().empty()) { \
	sql << " AND `subject`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (!obj.getBill_stage().empty()) { \
	sql << " AND `bill_stage`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_stage()); \
} \
if (obj.getIs_effective()!=-1) { \
	sql << " AND `is_effective`=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_effective()); \
} \
if (obj.getIs_closed()!=-1) { \
	sql << " AND `is_closed`=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_closed()); \
} \
if (obj.getIs_voided()!=-1) { \
	sql << " AND `is_voided`=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided()); \
}

uint64_t PurPayReqDAO::count(const FinPaymentReqDO & iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_payment_req";
	PUR_PAY_REQ_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);

}

std::list<FinPaymentReqDO> PurPayReqDAO::selectWithPage(const FinPaymentReqDO& jobj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM fin_payment_req";
	PUR_PAY_REQ_TERAM_PARSE(jobj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurPayReqFindBillMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<FinPaymentReqDO, PurPayReqFindBillMapper>(sqlStr, mapper, params);
}

std::list<FinPaymentReqDO>  PurPayReqDAO::selectBillNo(const string& no)
{
	string sql;
	sql = "SELECT * FROM fin_payment_req WHERE bill_no=?";
	PurPayReqFindBillMapper purPayReqFindBillMapper;
	list<FinPaymentReqDO> Bills = sqlSession->executeQuery<FinPaymentReqDO, PurPayReqFindBillMapper>(sql, purPayReqFindBillMapper, "%s", no);
	if (!Bills.empty()) {
		sql = "SELECT *  FROM fin_payment_req_entry WHERE bill_no=?";
		PurPayReqFindDetailBillMapper purPayReqFindDetailBillMapper;
		list<FinPaymentEntryReqDO> detailBills = sqlSession->executeQuery<FinPaymentEntryReqDO, PurPayReqFindDetailBillMapper>(sql, purPayReqFindDetailBillMapper, "%s", no);
		(*(Bills.begin())).setDetail(detailBills);
	}
	return Bills;
}

uint64_t PurPayReqDAO::insert(const FinPaymentBillReqDO& obj)
{
	string sql = "INSERT INTO `fin_payment_req` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	if (obj.getEffectiveTime() != "") {
		sql += ", '" + obj.getEffectiveTime() + "'";
	}
	else {
		sql += ", null";
	}
	sql += ", ?, ?, ?, ?, ?, ?";
	if (obj.getUpdateTime() != "") {
		sql += ", '" + obj.getUpdateTime() + "'";
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
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%d%d%s%s%i%s%s%s%s%s%i%i%i%s%s%s",
		obj.getId(), obj.getBillNo(), obj.getBillDate(), obj.getSrcBillType(),
		obj.getSrcBillId(), obj.getSrcNo(), obj.getSubject(),
		obj.getIsRubric(), obj.getPaymentType(), obj.getSupplierId(),
		obj.getOpDept(), obj.getOperator(), obj.getAmt(), 
		obj.getPaidAmt(), obj.getAttachment(),obj.getRemark(),
		obj.getIsAuto(), obj.getBillStage(),obj.getApprover(),
		obj.getBpmiInstanceId(), obj.getApprovalResultType(),
		obj.getApprovalRemark(), obj.getIsEffective(),
		obj.getIsClosed(), obj.getIsVoided(), obj.getSysOrgCode(),
		obj.getCreateBy(), obj.getCreateTime(), obj.getUpdateBy());
}

uint64_t PurPayReqDAO::insertEntry(const FinPaymentEntryDetaillDO& obj)
{
	string sql = "INSERT INTO fin_payment_req_entry` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	if (obj.getVersion() != 1) {
		sql += ", " + to_string(obj.getVersion());
	}
	else {
		sql += ", null";
	}
	sql += ")";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%d%d%s%s%s",
		obj.getId(), obj.getMid(), obj.getBillNo(),
		obj.getEntryNo(), obj.getSrcBillType(), obj.getSrcEntryId(),
		obj.getSrcEntryId(), obj.getSrcNo(), obj.getAmt(),
		obj.getPaidAmt(),  obj.getRemark(), obj.getCustom1(),
		obj.getCustom2());
}

list<FinPaymentBillReqDO> PurPayReqDAO::selectByBillNo(const string& billNo)
{
	string sql = "SELECT `id`,`bill_no` ,`bill_date`,`src_bill_type`,`src_bill_id`,`src_no`,`subject`,`is_rubric`,`payment_type`,`supplier_id`,`op_dept`,`operator` ,`amt`,`paid_amt`,`attachment`,`remark`,`is_auto`,`bill_stage` ,`approver` ,`bpmi_instance_id` ,`approval_result_type`,`approval_remark`,`is_effective`,`effective_time` ,`is_closed`,`is_voided` ,`sys_org_code`,`create_by` ,`create_time`,`update_by`,`update_time` ,`version` FROM pur_req WHERE `bill_no` = ?";
	purPayReqMapper mapper;
	return sqlSession->executeQuery<FinPaymentBillReqDO, purPayReqMapper>(sql, mapper, "%s", billNo);
}

list<FinPaymentEntryDetaillDO> PurPayReqDAO::selectEntryByBillNo(const string& billNo)
{
	string sql = "SELECT `id`,`mid`,`bill_no`,`entry_no`,`src_bill_type`,`src_bill_id`,`src_entry_id`, `src_no`, `amt`, `paid_amt`, `remark`,  `custom1`, `custom2`, `version` FROM `fin_payment_req_entry` WHERE `bill_no` = ?";
	PurPayReqEntryMapper mapper;
	return sqlSession->executeQuery<FinPaymentEntryDetaillDO, PurPayReqEntryMapper>(sql, mapper, "%s", billNo);
}