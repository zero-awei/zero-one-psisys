#include "stdafx.h"
#include "DeliveryMethodTypeService.h"
#include "dao/publicInterfaceDao/DeliveryMethodTypeDAO.h"

std::list<DeliveryMethodType> DeliveryMethodService::listAll()
{
    std::list<DeliveryMethodTypeDO> result;
    DeliveryMethodTypeDAO dao;
    result = dao.SelectMaterialType("1240566173593399297");
    std::list<DeliveryMethodType> VOs;

    for (auto res : result)
    {
        DeliveryMethodType vo;
        vo.setDict_id(res.getDict_id());
        vo.setDict_id(res.getId());
        vo.setName(res.getName());
        VOs.push_back(vo);
    }
    return VOs;
}
