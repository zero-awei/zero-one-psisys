#include "stdafx.h"
#include "service/publicInterfaceService/MaterialTypeService.h"
#include "MaterialTypeController.h"

JsonVO<std::list<MaterialType>> MaterialTypeController::executeQueryMaterialType()
{
    MaterialTypeService service;
    std::list<MaterialType> data = service.listAll();
    JsonVO<std::list<MaterialType>> res;
    res.success(data);
    return res;
}
