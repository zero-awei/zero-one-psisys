#include "stdafx.h"
#include "DeliveryMethodController.h"

JsonVO<std::list<DeliveryMethodType>> DeliveryMethodController::executeQueryDeliveryMethod()
{
    std::list<DeliveryMethodType> data;
    DeliveryMethodType vo;
    vo.setId("delivery");
    vo.setId("123");
    vo.setName(u8"01Õº¡È");
    data.push_back(vo);
    JsonVO<std::list<DeliveryMethodType>> res;
    res.success(data);
    return res;
}
