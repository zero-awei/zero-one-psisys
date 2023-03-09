#pragma once
/*
author: qiuqiu
date:2023/2/22
*/
#ifndef DELIVERYMETHODTYPEDO_H_
#define DELIVERYMETHODTYPEDO_H_

#include "../../GlobalInclude.h"
class DeliveryMethodTypeDO
{
	CC_SYNTHESIZE(uint64_t, dict_id, Dict_id);
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(std::string, item_text, Name);
public:
	BIND_TO_JSON(DeliveryMethodTypeDO, dict_id, id, item_text);
};
#endif