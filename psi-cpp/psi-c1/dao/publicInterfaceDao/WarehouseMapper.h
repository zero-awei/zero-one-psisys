#pragma once
#ifndef _WAREHOUSE_MAPPER_
#define _WAREHOUSE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/WarehouseDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class WarehouseMapper : public Mapper<WarehouseDO>
{
public:
	WarehouseDO mapper(ResultSet* resultSet) const override
	{
		WarehouseDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(5));
		return data;
	}
};

#endif // !_WAREHOUSE_MAPPER_