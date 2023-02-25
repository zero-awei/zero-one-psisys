#pragma once
#ifndef _PUR_QUOT_FIND_BILL_MAPPER_H_
#define _PUR_QUOT_FIND_BILL_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotFindBillMapper : public Mapper<PurQuotDO>
{
public:
	PurQuotDO mapper(ResultSet* resultSet) const override{
		PurQuotDO data;
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSubject(resultSet->getString("subject"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSupplier_id(resultSet->getString("supplier_id"));
		data.setSupplier_name(resultSet->getString("supplier_name"));
		data.setDelivery_time(resultSet->getString("delivery_time"));
		data.setQty(resultSet->getDouble("qty"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));
		data.setRemark(resultSet->getString("remark"));
		data.setIs_auto(resultSet->getInt("is_auto"));
		data.setIs_rubric(resultSet->getInt("is_rubric"));
		data.setEffective_time(resultSet->getString("effective_time"));
		data.setApprover(resultSet->getString("approver"));
		data.setCreate_time(resultSet->getString("create_time"));
		data.setCreate_by(resultSet->getString("create_by"));
		data.setSys_org_code(resultSet->getString("sys_org_code"));
		data.setUpdate_time(resultSet->getString("update_time"));
		data.setUpdate_by(resultSet->getString("update_by"));
		return data;
	}
};

#endif
