#pragma once
#ifndef _DELIVERY_TYPE_VO_
#define _DELIVERY_TYPE_VO_

#include "../GlobalInclude.h"

class DeliveryTypeVO
{
	CC_SYNTHESIZE(int, id, Id);
	CC_SYNTHESIZE(string, name, Name);
public:
	BIND_TO_JSON(DeliveryTypeVO, id, name);
};
#endif // !DELIVERY_TYPE_VO
