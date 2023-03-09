#include "stdafx.h"
#include "WarehouseController.h"
#include "../../service/public-interface/WarehouseService.h"

JsonVO<list<WarehouseVO>> WarehouseController::execQueryWarehouse()
{
	WarehouseService service;
	list<WarehouseVO> data = service.listAll();
	JsonVO<list<WarehouseVO>> res;
	res.success(data);
	return res;
}
