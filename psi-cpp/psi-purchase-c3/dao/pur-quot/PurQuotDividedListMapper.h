#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_MAPPER_H_
#define _PUR_QUOT_DIVIDED_LIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDividedListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotDividedListMapper : public Mapper<PurQuotDividedListDO>{
public:
	PurQuotDividedListDO mapper(ResultSet* resultSet) const override
	{
		PurQuotDividedListDO data;
		data.setBill_no(resultSet->getString(1));
		data.setMaterial_id(resultSet->getString(2));
		data.setUnit_id(resultSet->getString(3));
		data.setQty(resultSet->getString(4));
		data.setTax_rate(resultSet->getString(5));
		data.setPrice(resultSet->getString(6));
		data.setAmt(resultSet->getString(7));
		data.setRemark(resultSet->getString(8));
		data.setCustom1(resultSet->getString(9));
		data.setCustom2(resultSet->getString(10));
		return data;
	}
};
#endif
