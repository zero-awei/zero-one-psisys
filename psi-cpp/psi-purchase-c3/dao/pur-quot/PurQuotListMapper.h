#pragma once
#ifndef _PUR_QUOT_LIST_MAPPER_H_
#define _PUR_QUOT_LIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotListMapper : public Mapper<PurQuotListDO>
{
public:
	PurQuotListDO mapper(ResultSet* resultSet) const override
	{
		PurQuotListDO data;
		data.setSrc_no(resultSet->getString(1));
		data.setMaterial_id(resultSet->getString(2));
		data.setUnit_id(resultSet->getString(3));
		data.setQty(resultSet->getString(4));
		data.setTax_rate(resultSet->getString(5));
		data.setPrice(resultSet->getString(6));
		data.setDiscount_rate(resultSet->getString(7));
		data.setAmt(resultSet->getString(8));
		data.setRemark(resultSet->getString(9));
		data.setCustom1(resultSet->getString(10));
		data.setCustom2(resultSet->getString(11));
		return data;
	}
};

#endif
