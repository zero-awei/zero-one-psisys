#pragma once
#ifndef _WAREHOUSE_MAPPER_
#define _WAREHOUSE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/public-interface/WarehouseDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class WarehouseMapper : public Mapper<WarehouseDO>
{
public:
	WarehouseDO mapper(ResultSet* resultSet) const override
	{
		WarehouseDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_WAREHOUSE_MAPPER_