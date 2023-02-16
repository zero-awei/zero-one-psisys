#pragma once
#ifndef _WAREHOUSE_VO_
#define _WAREHOUSE_VO_

#include "../../GlobalInclude.h"

class WarehouseVO
{
	CC_SYNTHESIZE(int, id, Id);
	CC_SYNTHESIZE(string, name, Name);
public:
	BIND_TO_JSON(WarehouseVO, id, name);
};
#endif // !_WAREHOUSE_VO_
