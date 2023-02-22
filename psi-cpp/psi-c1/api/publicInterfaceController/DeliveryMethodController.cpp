#include "stdafx.h"
#include "DeliveryMethodController.h"
#include "service/publicInterfaceService/DeliveryMethodTypeService.h"

JsonVO<std::list<DeliveryMethodType>> DeliveryMethodController::executeQueryDeliveryMethod()
{
    std::list<DeliveryMethodType> data;
    DeliveryMethodService service;
    data = service.listAll();
    JsonVO<std::list<DeliveryMethodType>> res;
    res.success(data);
    return res;
}
