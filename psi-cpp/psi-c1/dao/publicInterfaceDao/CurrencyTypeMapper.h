#pragma once
#ifndef _CURRENCY_TYPE_MAPPER_
#define _CURRENCY_TYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/CurrencyTypeDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class CurrencyTypeMapper : public Mapper<CurrencyTypeDO>
{
public:
	CurrencyTypeDO mapper(ResultSet* resultSet) const override
	{
		CurrencyTypeDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_CURRENCY_TYPE_MAPPER_