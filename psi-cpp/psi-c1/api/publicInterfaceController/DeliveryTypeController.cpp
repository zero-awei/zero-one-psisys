#include "stdafx.h"
#include "DeliveryTypeController.h"

JsonVO<list<DeliveryTypeVO>> DeliveryTypeController::execQueryDeliveryType()
{
    list<DeliveryTypeVO> data;
    DeliveryTypeVO vo;
    vo.setId(1);
    vo.setName(u8"ÀÕªı…œ√≈");
    data.push_back(vo);
    JsonVO<list<DeliveryTypeVO>> res;
    res.success(data);
    return res;
}
