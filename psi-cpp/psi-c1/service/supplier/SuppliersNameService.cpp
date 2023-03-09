#include "stdafx.h"
#include "dao/supplier/SuppliersNameDAO.h"
#include "SuppliersNameService.h"

std::list<SuppliersName> SuppliersNameService::listAll()
{
    std::list<SuppliersNameDO> result;
    SuppliersNameDAO dao;
    result = dao.SelectMaterialType();
    std::list<SuppliersName> VOs;

    for (auto res : result)
    {
        SuppliersName vo;
        vo.setID(res.getID());
        vo.setName(res.getName());
        VOs.push_back(vo);
    }
    return VOs;


    return std::list<SuppliersName>();
}
