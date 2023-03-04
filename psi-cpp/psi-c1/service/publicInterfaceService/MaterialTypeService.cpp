#include "stdafx.h"
#include "dao/publicInterfaceDao/MaterialTypeDAO.h"
#include "MaterialTypeService.h"

std::list<MaterialType> MaterialTypeService::listAll()
{
    std::list<MaterialTypeDO> result;
    MaterialTypeDAO dao;
    result = dao.SelectMaterialType();
    std::list<MaterialType> VOs;

    for (auto res : result)
    {
        MaterialType vo;
        vo.setID(res.getID());
        vo.setPID(res.getPID());
        vo.setHas_Child(res.getHas_Child());
        vo.setName(res.getName());
        VOs.push_back(vo);
    }
    return VOs;
}
