#pragma once
#ifndef _PUR_QUOT_MAPPER_H_
#define _PUR_QUOT_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotMapper : public Mapper<PurQuotDO> {
public:
	PurQuotDO mapper(ResultSet* resultSet) const override {
		PurQuotDO data;
		data.setIs_temp_supplier(resultSet->getInt("is_temp_supplier"));
		data.setSupplier_name(resultSet->getString("supplier_name"));
		data.setSupplier_id(resultSet->getString("supplier_id"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setDelivery_place(resultSet->getString("delivery_place"));

		data.setDelivery_time(resultSet->getString("delivery_time"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));

		data.setQty(resultSet->getDouble("qty"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));

		data.setSubject(resultSet->getString("subject"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setIs_auto(resultSet->getInt("is_auto"));
		data.setRemark(resultSet->getString("remark"));

		data.setBpmi_instance_id(resultSet->getString("bpmi_instance_id"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setIs_rubric(resultSet->getInt("is_rubric"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));

		data.setCreate_time(resultSet->getString("create_time"));
		data.setEffective_time(resultSet->getString("effective_time"));
		data.setApprover(resultSet->getString("approver"));
		data.setUpdate_by(resultSet->getString("update_by"));
		data.setSys_org_code(resultSet->getString("sys_org_code"));

		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setCreate_by(resultSet->getString("create_by"));
		data.setApproval_remark(resultSet->getString("approval_remark"));
		return data;
	}
};
#endif


