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
	CC_SYNTHESIZE(std::string, dict_id, Dict_id);
	CC_SYNTHESIZE(std::string, id, Id);
	CC_SYNTHESIZE(std::string, name, Name);
public:
	BIND_TO_JSON(DeliveryMethodType, dict_id, id, name);
};



#endif // !DELIVERYMETHODTYPE_H_
