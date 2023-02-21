#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_MAPPER_H_
#define _PUR_QUOT_DIVIDED_LIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDividedListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotDividedListMapper : public Mapper<PurQuotDividedListDO>
{
public:
	PurQuotDividedListDO mapper(ResultSet* resultSet) const override
	{
		PurQuotDividedListDO data;
		//do something
		return data;
	}
};

#endif
