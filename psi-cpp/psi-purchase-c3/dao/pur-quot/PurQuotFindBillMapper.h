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
	PurQuotFindBillDO mapper(ResultSet* resultSet) const override
	{
		PurQuotFindBillDO data;
		data.setBill_no(resultSet->getString(1));
		data.setBill_date(resultSet->getString(2));
		data.setSubject(resultSet->getString(3));
		return data;
	}
};

#endif
