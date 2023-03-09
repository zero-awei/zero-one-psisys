#include "stdafx.h"
#include "PayMethodTypeService.h"
#include "../../domain/do/public-interface/PayMethodTypeDO.h"
#include "../../dao/public-interface/PayMethodTypeDAO.h"

std::list<PayMethodType> PayMethodTypeService::listAll()
{

    std::list<PayMethodTypeDO> result;
    PayMethodTypeDAO dao;
    result = dao.SelectMaterialType("1531507897164455937");
    std::list<PayMethodType> VOs;

    for (auto res : result)
    {
        PayMethodType vo;
        vo.setDict_id(res.getDict_id());
        vo.setDict_id(res.getId());
        vo.setName(res.getName());
        VOs.push_back(vo);
    }
    return VOs;
}
