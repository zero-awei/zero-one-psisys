#include "stdafx.h"
#include "service/public-interface/MaterialTypeService.h"
#include "MaterialTypeController.h"

JsonVO<std::list<MaterialType>> MaterialTypeController::executeQueryMaterialType()
{
    MaterialTypeService service;
    std::list<MaterialType> data = service.listAll();
    JsonVO<std::list<MaterialType>> res;
    res.success(data);
    return res;
}
