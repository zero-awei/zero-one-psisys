#include "stdafx.h"
#include "WarehouseController.h"

JsonVO<list<WarehouseVO>> WarehouseController::execQueryWarehouse()
{
    list<WarehouseVO> data;
    WarehouseVO vo;
    vo.setId(1);
    vo.setName(u8"1ºÅ²Ö¿â");
    data.push_back(vo);
    JsonVO<list<WarehouseVO>> res;
    res.success(data);
    return res;
}
