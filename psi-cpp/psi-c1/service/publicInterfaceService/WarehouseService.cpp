#include "stdafx.h"
#include "WarehouseService.h"
#include "../../dao/publicInterfaceDao/WarehouseDAO.h"

list<WarehouseVO> WarehouseService::listAll()
{
    WarehouseDAO dao;
    list<WarehouseDO> result = dao.selectWarehouse();
    list<WarehouseVO> vr;
    //把DO数据转换为VO
    for (WarehouseDO sub : result)
    {
        WarehouseVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}
