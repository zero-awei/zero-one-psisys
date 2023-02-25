/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/18 14:26:52

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
#include "PurOrderDAO.h"
#include "PurOrderMapper.h"
#include <sstream>

#define PUR_ORDER_MODIFY(obj, sql) \
SqlParams params; \
sql << "`update_time`=?"; \
SQLPARAMS_PUSH(params, "s", std::string, obj.getUpdate_time());\
if (!obj.getId().empty()) { \
    sql << ", `id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
} \
if (!obj.getBill_date().empty()) { \
    sql << ", `bill_date`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
} \
if (!obj.getSrc_bill_type().empty()) { \
    sql << ", `src_bill_type`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_bill_type()); \
} \
if (!obj.getSrc_bill_id().empty()) { \
    sql << ", `src_bill_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_bill_id()); \
} \
if (!obj.getSrc_no().empty()) { \
    sql << ", `src_no`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_no()); \
} \
if (!obj.getSubject().empty()) { \
    sql << ", `subject`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (!obj.getIs_rubric()) { \
    sql << ", `is_rubric`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIs_rubric()); \
} \
if (!obj.getPur_type().empty()) { \
    sql << ", `pur_type`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getPur_type()); \
} \
if (!obj.getSupplier_id().empty()) { \
    sql << ", `supplier_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSupplier_id()); \
} \
if (!obj.getContact().empty()) { \
    sql << ", `contact`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getContact()); \
} \
if (!obj.getPhone().empty()) { \
    sql << ", `phone`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getPhone()); \
} \
if (!obj.getFax().empty()) { \
    sql << ", `fax`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getFax()); \
} \
if (!obj.getEmail().empty()) { \
    sql << ", `email`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getEmail()); \
} \
if (!obj.getOp_dept().empty()) { \
    sql << ", `op_dept`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getOp_dept()); \
} \
if (!obj.getOp_er().empty()) { \
    sql << ", `operator`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getOp_er()); \
} \
if (!obj.getDelivery_method().empty()) { \
    sql << ", `delivery_method`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getDelivery_method()); \
} \
if (!obj.getDelivery_place().empty()) { \
    sql << ", `delivery_place`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getDelivery_place()); \
} \
if (!obj.getDelivery_time().empty()) { \
    sql << ", `delivery_time`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getDelivery_time()); \
} \
if (!obj.getTransport_method().empty()) { \
    sql << ", `transport_method`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getTransport_method()); \
} \
if (!obj.getPayment_method().empty()) { \
    sql << ", `payment_method`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getPayment_method()); \
} \
if (!obj.getSettle_method().empty()) { \
    sql << ", `settle_method`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSettle_method()); \
} \
if (!obj.getSettle_time().empty()) { \
    sql << ", `settle_time`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSettle_time()); \
} \
if (!obj.getInvoice_method().empty()) { \
    sql << ", `invoice_method`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getInvoice_method()); \
} \
if (!obj.getInvoice_type().empty()) { \
    sql << ", `invoice_type`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getInvoice_type()); \
} \
if (!obj.getCurrency().empty()) { \
    sql << ", `currency`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getCurrency()); \
} \
if (!obj.getExchange_rate()) { \
    sql << ", `exchange_rate`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getExchange_rate()); \
} \
if (!obj.getQty()) { \
    sql << ", `qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getQty()); \
} \
if (!obj.getAmt()) { \
    sql << ", `amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getAmt()); \
} \
if (!obj.getPrepayment_bal()) { \
    sql << ", `prepayment_bal`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getPrepayment_bal()); \
} \
if (!obj.getSettle_qty()) { \
    sql << ", `settle_qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettle_qty()); \
} \
if (!obj.getSettle_amt()) { \
    sql << ", `settle_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettle_amt()); \
} \
if (!obj.getIn_qty()) { \
    sql << ", `in_qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIn_qty()); \
} \
if (!obj.getIn_cost()) { \
    sql << ", `in_cost`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIn_cost()); \
} \
if (!obj.getSettled_amt()) { \
    sql << ", `settled_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettled_amt()); \
} \
if (!obj.getInvoiced_amt()) { \
    sql << ", `invoiced_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getInvoiced_amt()); \
} \
if (!obj.getAttachment().empty()) { \
    sql << ", `attachment`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getAttachment()); \
} \
if (!obj.getRemark().empty()) { \
    sql << ", `remark`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getRemark()); \
} \
if (!obj.getIs_auto()) { \
    sql << ", `is_auto`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIs_auto()); \
} \
if (!obj.getBill_stage().empty()) { \
    sql << ", `bill_stage`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_stage()); \
} \
if (!obj.getApprover().empty()) { \
    sql << ", `approver`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getApprover()); \
} \
if (!obj.getBpmi_instance_id().empty()) { \
    sql << ", `bpmi_instance_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBpmi_instance_id()); \
} \
if (!obj.getApproval_result_type().empty()) { \
    sql << ", `approval_result_type`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getApproval_result_type()); \
} \
if (!obj.getApproval_remark().empty()) { \
    sql << ", `approval_remark`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getApproval_remark()); \
} \
if (!obj.getIs_effective()) { \
    sql << ", `is_effective`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIs_effective()); \
} \
if (!obj.getEffective_time().empty()) { \
    sql << ", `effective_time`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getEffective_time()); \
} \
if (!obj.getIs_closed()) { \
    sql << ", `is_closed`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIs_closed()); \
} \
if (!obj.getIs_voided()) { \
    sql << ", `is_voided`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIs_voided()); \
} \
if (!obj.getSys_org_code().empty()) { \
    sql << ", `sys_org_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSys_org_code()); \
} \
if (!obj.getCreate_by().empty()) { \
    sql << ", `create_by`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getCreate_by()); \
} \
if (!obj.getCreate_time().empty()) { \
    sql << ", `create_time`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getCreate_time()); \
} \
if (!obj.getUpdate_by().empty()) { \
    sql << ", `update_by`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getUpdate_by()); \
} \
if (!obj.getVersion()) { \
    sql << ", `version`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getVersion()); \
} \
sql << " WHERE bill_no=?"; \
SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no());


// 插入数据
uint64_t PurOrderDAO::insert(const PurOrderDO& iObj)
{
    /*cout << " id: " << iObj.getId() << "\n" << " bill_no: " << iObj.getBill_no() << "\n" << " bill_date: " << iObj.getBill_date() << "\n" << " src_bill_type: " << iObj.getSrc_bill_type() << "\n" << " src_bill_id: " << iObj.getSrc_bill_id() << "\n" << " src_no: " << iObj.getSrc_no() << "\n" << " subject: " << iObj.getSubject() << "\n" << " is_rubric: " << iObj.getIs_rubric() << "\n" << " pur_type: " << iObj.getPur_type() << "\n" << " supplier_id: " << iObj.getSupplier_id() << "\n" << " contact: " << iObj.getContact() << "\n" << " phone: " << iObj.getPhone() << "\n" << " fax: " << iObj.getFax() << "\n" << " email: " << iObj.getEmail() << "\n" << " op_dept: " << iObj.getOp_dept() << "\n" << " operator: " << iObj.getOp_er() << "\n" << " delivery_method: " << iObj.getDelivery_method() << "\n" << " delivery_place: " << iObj.getDelivery_place() << "\n" << " delivery_time: " << iObj.getDelivery_time() << "\n" << " transport_method: " << iObj.getTransport_method() << "\n" << " payment_method: " << iObj.getPayment_method() << "\n" << " settle_method: " << iObj.getSettle_method() << "\n" << " settle_time: " << iObj.getSettle_time() << "\n" << " invoice_method: " << iObj.getInvoice_method() << "\n" << " invoice_type: " << iObj.getInvoice_type() << "\n" << " currency: " << iObj.getCurrency() << "\n" << " exchange_rate: " << iObj.getExchange_rate() << "\n" << " qty: " << iObj.getQty() << "\n" << " amt: " << iObj.getAmt() << "\n" << " prepayment_bal: " << iObj.getPrepayment_bal() << "\n" << " settle_qty: " << iObj.getSettle_qty() << "\n" << " settle_amt: " << iObj.getSettle_amt() << "\n" << " in_qty: " << iObj.getIn_qty() << "\n" << " in_cost: " << iObj.getIn_cost() << "\n" << " settled_amt: " << iObj.getSettled_amt() << "\n" << " invoiced_amt: " << iObj.getInvoiced_amt() << "\n" << " attachment: " << iObj.getAttachment() << "\n" << " remark: " << iObj.getRemark() << "\n" << " is_auto: " << iObj.getIs_auto() << "\n" << " bill_stage: " << iObj.getBill_stage() << "\n" << " approver: " << iObj.getApprover() << "\n" << " bpmi_instance_id: " << iObj.getBpmi_instance_id() << "\n" << " approval_result_type: " << iObj.getApproval_result_type() << "\n" << " approval_remark: " << iObj.getApproval_remark() << "\n" << " is_effective: " << iObj.getIs_effective() << "\n" << " effective_time: " << iObj.getEffective_time() << "\n" << " is_closed: " << iObj.getIs_closed() << "\n" << " is_voided: " << iObj.getIs_voided() << "\n" << " sys_org_code: " << iObj.getSys_org_code() << "\n" << " create_by: " << iObj.getCreate_by() << "\n" << " create_time: " << iObj.getCreate_time() << "\n" << " update_by: " << iObj.getUpdate_by() << "\n" << " update_time: " << iObj.getUpdate_time() << "\n" << " version: " << iObj.getVersion() << endl; */

    string sql = "INSERT INTO `pur_order` (`id`,`bill_no`,`bill_date`,`src_bill_type`,`src_bill_id`,`src_no`,`subject`,`is_rubric`,`pur_type`,`supplier_id`,`contact`,`phone`,`fax`,`email`,`op_dept`,`operator`,`delivery_method`,`delivery_place`,`delivery_time`,`transport_method`,`payment_method`,`settle_method`,`settle_time`,`invoice_method`,`invoice_type`,`currency`,`exchange_rate`,`qty`,`amt`,`prepayment_bal`,`settle_qty`,`settle_amt`,`in_qty`,`in_cost`,`settled_amt`,`invoiced_amt`,`attachment`,`remark`,`is_auto`,`bill_stage`,`approver`,`bpmi_instance_id`,`approval_result_type`,`approval_remark`,`is_effective`,`effective_time`,`is_closed`,`is_voided`,`sys_org_code`,`create_by`,`create_time`,`update_by`,`update_time`, `version`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"; 
    string result = sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d%d%d%d%d%d%d%d%d%d%s%s%i%s%s%s%s%s%i%s%i%i%s%s%s%s%s%i", iObj.getId(), iObj.getBill_no(), iObj.getBill_date(), iObj.getSrc_bill_type(), iObj.getSrc_bill_id(), iObj.getSrc_no(), iObj.getSubject(), iObj.getIs_rubric(), iObj.getPur_type(), iObj.getSupplier_id(), iObj.getContact(), iObj.getPhone(), iObj.getFax(), iObj.getEmail(), iObj.getOp_dept(), iObj.getOp_er(), iObj.getDelivery_method(), iObj.getDelivery_place(), iObj.getDelivery_time(), iObj.getTransport_method(), iObj.getPayment_method(), iObj.getSettle_method(), iObj.getSettle_time(), iObj.getInvoice_method(), iObj.getInvoice_type(), iObj.getCurrency(), iObj.getExchange_rate(), iObj.getQty(), iObj.getAmt(), iObj.getPrepayment_bal(), iObj.getSettle_qty(), iObj.getSettle_amt(), iObj.getIn_qty(), iObj.getIn_cost(), iObj.getSettled_amt(), iObj.getInvoiced_amt(), iObj.getAttachment(), iObj.getRemark(), iObj.getIs_auto(), iObj.getBill_stage(), iObj.getApprover(), iObj.getBpmi_instance_id(), iObj.getApproval_result_type(), iObj.getApproval_remark(), iObj.getIs_effective(), iObj.getEffective_time(), iObj.getIs_closed(), iObj.getIs_voided(), iObj.getSys_org_code(), iObj.getCreate_by(), iObj.getCreate_time(), iObj.getUpdate_by(), iObj.getUpdate_time(), iObj.getVersion());
    return result;
}

// 更新数据
uint64_t PurOrderDAO::update(const PurOrderDO& iObj)
{
    stringstream sql;
    sql << "UPDATE `pur_order` SET ";
    PUR_ORDER_MODIFY(iObj, sql);
    
    string sqlStr = sql.str();
    cout << sqlStr;
    return sqlSession->executeUpdate(sqlStr, params);
}