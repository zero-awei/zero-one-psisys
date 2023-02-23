#pragma once
#ifndef _PUR_QUOT_BASE_MAPPER_H_
#define _PUR_QUOT_BASE_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotBaseMapper : public Mapper<PurQuotDO>{
public:
	PurQuotDO mapper(ResultSet* resultSet) const override{
		PurQuotDO data;
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setSubject(resultSet->getString("subject"));
		data.setIs_temp_supplier(resultSet->getInt("is_temp_supplier"));
		data.setSupplier_id(resultSet->getString("supplier_id"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setDelivery_time(resultSet->getString("delivery_time"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));
		data.setRemark(resultSet->getString("remark"));
		data.setApproval_remark(resultSet->getString("approval_remark"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		//Ã÷Ï¸×Ö¶Î
		return data;
	}
};

#endif