#include "stdafx.h"
#include "PayMethodController.h"
#include "service/public-interface/PayMethodTypeService.h"

JsonVO<std::list<PayMethodType>> PayMethodController::executeQueryPayMethod()
{
    std::list<PayMethodType> data;
    PayMethodTypeService service;
    data = service.listAll();
    JsonVO<std::list<PayMethodType>> res;
    res.success(data);
    return res;
}
