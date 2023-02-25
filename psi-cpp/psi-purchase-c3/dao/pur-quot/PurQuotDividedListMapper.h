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
		data.setBill_no(resultSet->getString("bill_no"));
		data.setMaterial_id(resultSet->getString("material_id"));
		data.setUnit_id(resultSet->getString("unit_id"));
		data.setQty(resultSet->getDouble("qty"));
		data.setTax_rate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};
#endif