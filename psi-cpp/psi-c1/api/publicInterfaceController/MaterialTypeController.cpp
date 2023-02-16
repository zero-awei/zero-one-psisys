#include "stdafx.h"
#include "MaterialTypeController.h"

JsonVO<std::list<MaterialType>> MaterialTypeController::executeQueryMaterialType()
{
    std::list<MaterialType> data;
    MaterialType vo;
    vo.setID("123");
    vo.setName(u8"01Õº¡È");
    data.push_back(vo);
    JsonVO<std::list<MaterialType>> res;
    res.success(data);
    return res;
}
