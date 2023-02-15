#pragma once
#ifndef _WAREHOUSE_CONTROLLER_
#define _WAREHOUSE_CONTROLLER_

#include "../domain/vo/JsonVO.h"
#include "../domain/vo/WarehouseVO.h"

class WarehouseController
{
public:
	CREATE_API_FUN_QUERY3(queryWarehouse, execQueryWarehouse);
private:
	JsonVO<list<WarehouseVO>> execQueryWarehouse();
};
#endif // _WAREHOUSE_CONTROLLER_