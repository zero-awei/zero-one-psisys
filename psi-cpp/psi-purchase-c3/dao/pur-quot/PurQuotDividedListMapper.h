#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_MAPPER_H_
#define _PUR_QUOT_DIVIDED_LIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotDividedListMapper : public Mapper<PurQuotEntryDO>{
public:
	PurQuotEntryDO mapper(ResultSet* resultSet) const override
	{
		PurQuotEntryDO data;
		data.setBill_no(resultSet->getString(1));
		data.setMaterial_id(resultSet->getString(2));
		data.setUnit_id(resultSet->getString(3));
		data.setQty(resultSet->getDouble(4));
		data.setTax_rate(resultSet->getDouble(5));
		data.setPrice(resultSet->getDouble(6));
		data.setAmt(resultSet->getDouble(7));
		data.setRemark(resultSet->getString(8));
		data.setCustom1(resultSet->getString(9));
		data.setCustom2(resultSet->getString(10));
		return data;
	}
};
#endif
