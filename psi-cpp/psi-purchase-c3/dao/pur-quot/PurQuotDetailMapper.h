#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotDetailMapper : public Mapper<PurQuotEntryDO>
{
public:
	PurQuotEntryDO mapper(ResultSet* resultSet) const override
	{
		PurQuotEntryDO data;
		data.setSrc_no(resultSet->getString(21));
		data.setMaterial_id(resultSet->getString(22));
		data.setUnit_id(resultSet->getString(23));
		data.setQty(resultSet->getDouble(24));
		data.set(resultSet->getDouble(25));
		data.setPrice(resultSet->getDouble(26));
		data.setDiscount_rate(resultSet->getDouble(27));
		data.setAmt(resultSet->getDouble(28));
		data.setRemark(resultSet->getString(29));
		data.setCustom1(resultSet->getString(30));
		data.setCustom2(resultSet->getString(31));
//Ã÷Ï¸×Ö¶Î
		return data;
	}
};

#endif


