/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2022/2/21 8:50:55

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
#include <sstream>
#include "PurReqDAO.h"
#include "ReqMapper.h"
#include "PurReqEntryMapper.h"
#include "PurReqFindDetailBillMapper.h"
#include "PurReqFindBillMapper.h"


#define PUR_REQ_TERAM_PARSE(obj, sql) \
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

uint64_t PurReqDAO::count(const PurReqDO& iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_req";
	PUR_REQ_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);

}
std::list<PurReqDO> PurReqDAO::selectWithPage(const PurReqDO& jobj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM pur_req";
	PUR_REQ_TERAM_PARSE(jobj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurReqFindBillMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurReqDO, PurReqFindBillMapper>(sqlStr, mapper, params);
}

std::list<PurReqDO>  PurReqDAO::selectByNo(const string& no)
{
	string sql;
	sql = "SELECT * FROM pur_req WHERE bill_no=?";
	PurReqFindBillMapper purReqFindBillMapper;
	list<PurReqDO> Bills = sqlSession->executeQuery<PurReqDO, PurReqFindBillMapper>(sql, purReqFindBillMapper, "%s", no);
	if (!Bills.empty()) {
		sql = "SELECT *  FROM pur_req_entry WHERE bill_no=?";
		PurReqFindDetailBillMapper purReqFindDetailBillMapper;
		list<PurReqEntryDO> detailBills = sqlSession->executeQuery<PurReqEntryDO, PurReqFindDetailBillMapper>(sql, purReqFindDetailBillMapper, "%s", no);
		(*(Bills.begin())).setDetail(detailBills);
	}
	return Bills;
}



// 添加申请(保存/提交) 插入总表数据
uint64_t PurReqDAO::insert(const PurReqAdamDO& obj)
{
	string sql = "INSERT INTO `pur_req` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
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
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%d%d%d%s%s%i%s%s%s%s%s%i%i%i%s%s%s%s",
		obj.getId(),obj.getBillNo(), obj.getBillDate(), obj.getSrcBillType(), 
		obj.getSrcBillId(), obj.getSrcNo(), obj.getSubject(), 
		obj.getIsRubric(), obj.getPurType(), obj.getRequestDept(), 
		obj.getRequester(), obj.getRequestTime(), obj.getQty(), 
		obj.getAmt(), obj.getOrderedQty(), obj.getAttachment(), 
		obj.getRemark(), obj.getIsAuto(), obj.getBillStage(), 
		obj.getApprover(), obj.getBpmiInstanceId(), obj.getApprovalResultType(), 
		obj.getApprovalRemark(), obj.getIsEffective(), 
		obj.getIsClosed(), obj.getIsVoided(), obj.getSysOrgCode(), 
		obj.getCreateBy(), obj.getCreateTime(),obj.getUpdateBy());
}

uint64_t PurReqDAO::insertEntry(const PurReqEntryAdamDO& obj)
{
	string sql = "INSERT INTO `pur_req_entry` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	if (obj.getTaxRate() != -1) {
		sql += ", " + to_string(obj.getTaxRate());
	}
	else {
		sql += ", null";
	}
	sql += ", ?, ?, ?, ?, ?, ?, ?";
	if (obj.getVersion() != 1) {
		sql += ", " + to_string(obj.getVersion());
	}
	else {
		sql += ", null";
	}
	sql += ")";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%d%d%d%s%d%s%s%s",
		obj.getId(), obj.getMid(), obj.getBillNo(),
		obj.getEntryNo(), obj.getSrcBillType(), obj.getSrcEntryId(),
		obj.getSrcEntryId(), obj.getSrcNo(), obj.getMaterialId(),
		obj.getUnitId(), obj.getQty(),
		obj.getPrice(), obj.getAmt(), obj.getSuggestSupplierId(),
		obj.getOrderedQty(), obj.getRemark(), obj.getCustom1(),
		obj.getCustom2());
}

int PurReqDAO::update(const PurReqAdamDO& obj)
{
	string sql = "UPDATE `pur_req` SET `is_effective`=?, `effective_time`=?, `is_closed`=?, `is_voided`=?, `update_by`=?, `update_time`=?  WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%i%s%i%i%s%s%s", obj.getIsEffective(), obj.getEffectiveTime(), obj.getIsClosed(), obj.getIsVoided(), obj.getUpdateBy(), obj.getUpdateTime(), obj.getBillNo());
}

int PurReqDAO::deleteByBillNo(string billNo)
{
	string sql = "DELETE FROM `pur_req` WHERE `bill_no`=?";
	int flag = sqlSession->executeUpdate(sql, "%s", billNo);
	sql = "DELETE FROM `pur_req_entry` WHERE `bill_no`=?";
	return (flag && sqlSession->executeUpdate(sql, "%s", billNo));
}

list<PurReqAdamDO> PurReqDAO::selectByBillNo(const string& billNo)
{
	string sql = "SELECT `id`,`bill_no` ,`bill_date`,`src_bill_type`,`src_bill_id`,`src_no`,`subject`,`is_rubric`,`pur_type`,`request_dept`,`requester`,`request_time` ,`qty`,`amt`,`ordered_qty`,`attachment`,`remark`,`is_auto`,`bill_stage` ,`approver` ,`bpmi_instance_id` ,`approval_result_type`,`approval_remark`,`is_effective`,`effective_time` ,`is_closed`,`is_voided` ,`sys_org_code`,`create_by` ,`create_time`,`update_by`,`update_time` ,`version` FROM pur_req WHERE `bill_no` = ?";
	PurReqMapper mapper;
	return sqlSession->executeQuery<PurReqAdamDO, PurReqMapper>(sql, mapper, "%s", billNo);
}

list<PurReqEntryAdamDO> PurReqDAO::selectEntryByBillNo(const string& billNo)
{
	string sql = "SELECT `id`,`mid`,`bill_no`,`entry_no`,`src_bill_type`,`src_bill_id`,`src_entry_id`, `src_no`, `material_id`, `unit_id`, `qty`,  `tax_rate`,  `price`, `amt`, `suggest_supplier_id`, `ordered_qty` , `remark`,  `custom1`, `custom2`, `version` FROM `pur_req_entry` WHERE `bill_no` = ?";
	PurReqEntryMapper mapper;
	return sqlSession->executeQuery<PurReqEntryAdamDO, PurReqEntryMapper>(sql, mapper, "%s", billNo);
}


