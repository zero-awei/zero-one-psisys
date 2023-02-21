#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotFindDetailBillDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotFindDetailBillMapper : public Mapper<PurQuotFindDetailBillDO>
{
public:
	PurQuotFindDetailBillDO mapper(ResultSet* resultSet) const override
	{
		PurQuotFindDetailBillDO data;
		//do something
		return data;
	}
};

#endif
