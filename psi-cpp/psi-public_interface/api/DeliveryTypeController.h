#pragma once
#ifndef _DELIVERY_TYPE_CONTROLLER_
#define _DELIVERY_TYPE_CONTROLLER_

#include "../domain/vo/JsonVO.h"
#include "../domain/vo/DeliveryTypeVO.h"
class DeliveryTypeController
{
public:
	CREATE_API_FUN_QUERY3(queryDeliveryType, execQueryDeliveryType);
private:
	JsonVO<list<DeliveryTypeVO>> execQueryDeliveryType();
};
#endif // !_DELIVERY_TYPE_CONTROLLER_
