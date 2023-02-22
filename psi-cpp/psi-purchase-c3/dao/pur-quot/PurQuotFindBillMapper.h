#pragma once
#ifndef _PUR_QUOT_FIND_BILL_MAPPER_H_
#define _PUR_QUOT_FIND_BILL_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotFindBillDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotMapper : public Mapper<PurQuotFindBillDO>
{
public:
	PurQuotFindBillDO mapper(ResultSet* resultSet) const override{
		PurQuotFindBillDO data;
		data.setBill_no(resultSet->getString(1));
		data.setBill_date(resultSet->getString(2));
		data.setSubject(resultSet->getString(3));
		data.setSrc_no(resultSet->getString(4));
		data.setSupplier_id(resultSet->getString(5));
		data.setSupplier_name(resultSet->getString(6));
		data.setDelivery_time(resultSet->getString(7));
		data.setQty(resultSet->getString(8));
		data.setAmt(resultSet->getString(9));
		data.setBill_stage(resultSet->getString(10));
		data.setIs_effective(resultSet->getString(11));
		data.setIs_closed(resultSet->getString(12));
		data.setIs_voided(resultSet->getString(13));
		data.setPayment_method(resultSet->getString(14));
		data.setDelivery_place(resultSet->getString(15));
		data.setContact(resultSet->getString(16));
		data.setPhone(resultSet->getString(17));
		data.setFax(resultSet->getString(18));
		data.setEmail(resultSet->getString(19));
		data.setRemark(resultSet->getString(20));
		data.setIs_auto(resultSet->getString(21));
		data.setIs_rubric(resultSet->getString(22));
		data.setEffective_time(resultSet->getString(23));
		data.setApprover(resultSet->getString(24));
		data.setCreate_time(resultSet->getString(25));
		data.setCreate_by(resultSet->getString(26));
		data.setSys_org_code(resultSet->getString(27));
		data.setUpdate_time(resultSet->getString(28));
		data.setUpdate_by(resultSet->getString(29));
		return data;
	}
};

#endif
