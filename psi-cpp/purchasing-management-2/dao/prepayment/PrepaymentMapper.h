#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurOrder/PurOrderDO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"

/**
 * 普通查询列表字段匹配映射
 */
class PurOrderMapper : public Mapper<PurOrderDO>
{
public:
	PurOrderDO mapper(ResultSet* resultSet) const override
	{
		PurOrderDO data;
		data.setId(resultSet->getString("id"));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSubject(resultSet->getString("subject"));
		data.setIs_rubric(resultSet->getInt("is_rubric"));
		data.setPur_type(resultSet->getString("pur_type"));
		data.setSupplier_id(resultSet->getString("supplier_id"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setContact(resultSet->getString("contact"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));
		data.setOp_dept(resultSet->getString("op_dept"));
		data.setOp_er(resultSet->getString("op_er"));
		data.setDelivery_method(resultSet->getString("delivery_method"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setDelivery_time(resultSet->getString("delivery_time"));
		data.setTransport_method(resultSet->getString("transport_method"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setSettle_method(resultSet->getString("settle_method"));
		data.setSettle_time(resultSet->getString("settle_time"));
		data.setInvoice_method(resultSet->getString("invoice_method"));
		data.setInvoice_type(resultSet->getString("invoice_type"));
		data.setCurrency(resultSet->getString("currency"));
		data.setExchange_rate(resultSet->getInt("exchange_rate"));
		data.setQty(resultSet->getInt("qty"));
		data.setAmt(resultSet->getInt("amt"));
		data.setPrepayment_bal(resultSet->getInt("prepayment_bal"));
		data.setSettle_qty(resultSet->getInt("settle_qty"));
		data.setSettle_amt(resultSet->getInt("settle_amt"));
		data.setIn_qty(resultSet->getInt("in_qty"));
		data.setIn_cost(resultSet->getInt("in_cost"));
		data.setSettled_amt(resultSet->getInt("settled_amt"));
		data.setInvoiced_amt(resultSet->getInt("invoiced_amt"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setRemark(resultSet->getString("remark"));
		data.setIs_auto(resultSet->getInt("is_auto"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setApprover(resultSet->getString("approver"));
		data.setBpmi_instance_id(resultSet->getString("bpmi_instance_id"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		data.setApproval_remark(resultSet->getString("approval_remark"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setEffective_time(resultSet->getString("effective_time"));
		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setSys_org_code(resultSet->getString("sys_org_code"));
		data.setCreate_by(resultSet->getString("create_by"));
		data.setCreate_time(resultSet->getString("create_time"));
		data.setUpdate_by(resultSet->getString("update_by"));
		data.setUpdate_time(resultSet->getString("update_time"));
		data.setVersion(resultSet->getInt("version"));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_

/**
 * 指定单据详情基础信息字段匹配映射
 */
class PurOrderDetailMapper : public Mapper<PurOrderDO>
{
public:
	PurOrderDO mapper(ResultSet* resultSet) const override
	{
		PurOrderDO data;
		data.setId(to_string(resultSet->getInt("id")));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSubject(resultSet->getString("subject"));

		data.setRemark(resultSet->getString("remark"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setApproval_remark(resultSet->getString("approval_remark"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		return data;
	}
};


/**
 * 指定单据详情基础信息字段匹配映射
 */
class PurOrderEntryMapper : public Mapper<PurOrderEntryDO>
{
public:
	PurOrderEntryDO mapper(ResultSet* resultSet) const override
	{
		PurOrderEntryDO data;

		data.setId(resultSet->getString("id"));
		data.setMid(resultSet->getString("mid"));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setEntry_no(resultSet->getString("entry_no"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_entry_id(resultSet->getString("src_entry_id"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setMaterial_id(resultSet->getString("material_id"));
		data.setUnit_id(resultSet->getString("unit_id"));
		data.setQty(resultSet->getInt("qty"));
		data.setTax_rate(resultSet->getInt("tax_rate"));
		data.setPrice(resultSet->getInt("price"));
		data.setDiscount_rate(resultSet->getInt("discount_rate"));
		data.setTax(resultSet->getInt("tax"));
		data.setAmt(resultSet->getInt("amt"));
		data.setIn_qty(resultSet->getInt("in_qty"));
		data.setIn_cost(resultSet->getInt("in_cost"));
		data.setSettle_qty(resultSet->getInt("settle_qty"));
		data.setSettle_amt(resultSet->getInt("settle_amt"));
		data.setInvoiced_qty(resultSet->getInt("invoiced_qty"));
		data.setInvoiced_amt(resultSet->getInt("invoiced_amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		data.setVersion(resultSet->getInt("version"));
		return data;
	}
};
