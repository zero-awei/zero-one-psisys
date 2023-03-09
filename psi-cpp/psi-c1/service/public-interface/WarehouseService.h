#pragma once
#ifndef _WAREHOUSE_SERVICE_
#define _WAREHOUSE_SERVICE_

#include <list>
#include "../../domain/vo/public-interface/WarehouseVO.h"


class WarehouseService
{
public:
	//≤È—Ø≤÷ø‚¡–±Ì
	list<WarehouseVO> listAll();
};
#endif // !_WAREHOUSE_SERVICE_