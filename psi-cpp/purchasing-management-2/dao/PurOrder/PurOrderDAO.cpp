/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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

#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getId()).empty()) { \
    sql << " AND `id`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getId()); \
} \
if (!obj.getBill_no()).empty()) { \
    sql << " AND `bill_no`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getBill_no()); \
} \
if (!obj.getBill_date()).empty()) { \
    sql << " AND `bill_date`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getBill_date()); \
} \
if (!obj.getSrc_bill_type()).empty()) { \
    sql << " AND `src_bill_type`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSrc_bill_type()); \
} \
if (!obj.getSrc_bill_id()).empty()) { \
    sql << " AND `src_bill_id`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSrc_bill_id()); \
} \
if (!obj.getSrc_no()).empty()) { \
    sql << " AND `src_no`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSrc_no()); \
} \
if (!obj.getSubject()).empty()) { \
    sql << " AND `subject`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSubject()); \
} \
if (!obj.getIs_rubric()).empty()) { \
    sql << " AND `is_rubric`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIs_rubric()); \
} \
if (!obj.getPur_type()).empty()) { \
    sql << " AND `pur_type`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getPur_type()); \
} \
if (!obj.getSupplier_id()).empty()) { \
    sql << " AND `supplier_id`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSupplier_id()); \
} \
if (!obj.getContact()).empty()) { \
    sql << " AND `contact`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getContact()); \
} \
if (!obj.getPhone()).empty()) { \
    sql << " AND `phone`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getPhone()); \
} \
if (!obj.getFax()).empty()) { \
    sql << " AND `fax`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getFax()); \
} \
if (!obj.getEmail()).empty()) { \
    sql << " AND `email`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getEmail()); \
} \
if (!obj.getOp_dept()).empty()) { \
    sql << " AND `op_dept`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getOp_dept()); \
} \
if (!obj.getOp_er()).empty()) { \
    sql << " AND `operator`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getOp_er()); \
} \
if (!obj.getDelivery_method()).empty()) { \
    sql << " AND `delivery_method`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getDelivery_method()); \
} \
if (!obj.getDelivery_place()).empty()) { \
    sql << " AND `delivery_place`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getDelivery_place()); \
} \
if (!obj.getDelivery_time()).empty()) { \
    sql << " AND `delivery_time`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getDelivery_time()); \
} \
if (!obj.getTransport_method()).empty()) { \
    sql << " AND `transport_method`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getTransport_method()); \
} \
if (!obj.getPayment_method()).empty()) { \
    sql << " AND `payment_method`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getPayment_method()); \
} \
if (!obj.getSettle_method()).empty()) { \
    sql << " AND `settle_method`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSettle_method()); \
} \
if (!obj.getSettle_time()).empty()) { \
    sql << " AND `settle_time`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSettle_time()); \
} \
if (!obj.getInvoice_method()).empty()) { \
    sql << " AND `invoice_method`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getInvoice_method()); \
} \
if (!obj.getInvoice_type()).empty()) { \
    sql << " AND `invoice_type`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getInvoice_type()); \
} \
if (!obj.getCurrency()).empty()) { \
    sql << " AND `currency`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getCurrency()); \
} \
if (!obj.getExchange_rate()).empty()) { \
    sql << " AND `exchange_rate`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getExchange_rate()); \
} \
if (!obj.getQty()).empty()) { \
    sql << " AND `qty`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getQty()); \
} \
if (!obj.getAmt()).empty()) { \
    sql << " AND `amt`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getAmt()); \
} \
if (!obj.getPrepayment_bal()).empty()) { \
    sql << " AND `prepayment_bal`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getPrepayment_bal()); \
} \
if (!obj.getSettle_qty()).empty()) { \
    sql << " AND `settle_qty`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getSettle_qty()); \
} \
if (!obj.getSettle_amt()).empty()) { \
    sql << " AND `settle_amt`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getSettle_amt()); \
} \
if (!obj.getIn_qty()).empty()) { \
    sql << " AND `in_qty`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIn_qty()); \
} \
if (!obj.getIn_cost()).empty()) { \
    sql << " AND `in_cost`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIn_cost()); \
} \
if (!obj.getSettled_amt()).empty()) { \
    sql << " AND `settled_amt`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getSettled_amt()); \
} \
if (!obj.getInvoiced_amt()).empty()) { \
    sql << " AND `invoiced_amt`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getInvoiced_amt()); \
} \
if (!obj.getAttachment()).empty()) { \
    sql << " AND `attachment`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getAttachment()); \
} \
if (!obj.getRemark()).empty()) { \
    sql << " AND `remark`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getRemark()); \
} \
if (!obj.getIs_auto()).empty()) { \
    sql << " AND `is_auto`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIs_auto()); \
} \
if (!obj.getBill_stage()).empty()) { \
    sql << " AND `bill_stage`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getBill_stage()); \
} \
if (!obj.getApprover()).empty()) { \
    sql << " AND `approver`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getApprover()); \
} \
if (!obj.getBpmi_instance_id()).empty()) { \
    sql << " AND `bpmi_instance_id`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getBpmi_instance_id()); \
} \
if (!obj.getApproval_result_type()).empty()) { \
    sql << " AND `approval_result_type`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getApproval_result_type()); \
} \
if (!obj.getApproval_remark()).empty()) { \
    sql << " AND `approval_remark`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getApproval_remark()); \
} \
if (!obj.getIs_effective()).empty()) { \
    sql << " AND `is_effective`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIs_effective()); \
} \
if (!obj.getEffective_time()).empty()) { \
    sql << " AND `effective_time`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getEffective_time()); \
} \
if (!obj.getIs_closed()).empty()) { \
    sql << " AND `is_closed`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIs_closed()); \
} \
if (!obj.getIs_voided()).empty()) { \
    sql << " AND `is_voided`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getIs_voided()); \
} \
if (!obj.getSys_org_code()).empty()) { \
    sql << " AND `sys_org_code`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getSys_org_code()); \
} \
if (!obj.getCreate_by()).empty()) { \
    sql << " AND `create_by`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getCreate_by()); \
} \
if (!obj.getCreate_time()).empty()) { \
    sql << " AND `create_time`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getCreate_time()); \
} \
if (!obj.getUpdate_by()).empty()) { \
    sql << " AND `update_by`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getUpdate_by()); \
} \
if (!obj.getUpdate_time()).empty()) { \
    sql << " AND `update_time`=?"; \
    SQLPARAMS_PUSH(params, " s ", std::string, obj.getUpdate_time()); \
} \
if (!obj.getVersion()).empty()) { \
    sql << " AND `version`=?"; \
    SQLPARAMS_PUSH(params, " d ", std::string, obj.getVersion()); \
}
uint64_t PurOrderDAO::insert(const PurOrderDO& iObj)
{
	return 0;
}