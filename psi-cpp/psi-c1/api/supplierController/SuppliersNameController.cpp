#include "stdafx.h"
#include "SuppliersNameController.h"
#include "service/supplierService/SuppliersNameService.h"

JsonVO<std::list<SuppliersName>> SuppliersNameController::executeQuerySuppliersName()
{   
    SuppliersNameService service;
    std::list<SuppliersName> data = service.listAll();
    JsonVO<std::list<SuppliersName>> res;
    res.success(data);
    return res;
}
