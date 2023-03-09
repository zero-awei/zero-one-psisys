#pragma once
/*
* 交货方式类型
author: qiuqiu
date: 2023/2/13
*/

#ifndef DELIVERYMETHODTYPE_H_
#define DELIVERYMETHODTYPE_H_

#include "../../GlobalInclude.h"

class DeliveryMethodType
{
	CC_SYNTHESIZE(uint64_t, dict_id, Dict_id);
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(std::string, item_text, Name);
public:
	BIND_TO_JSON(DeliveryMethodType, dict_id, id, item_text);
};



#endif // !DELIVERYMETHODTYPE_H_
