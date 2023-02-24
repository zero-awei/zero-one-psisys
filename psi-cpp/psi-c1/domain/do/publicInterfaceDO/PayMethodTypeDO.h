#pragma once
/*
author: qiuqiu
date:2023/2/22
*/

#ifndef PAYMETHODTYPEDO_H_
#define PAYMETHODTYPEDO_H_

#include "../DoInclude.h"

class PayMethodTypeDO
{
	CC_SYNTHESIZE(uint64_t, dict_id, Dict_id);
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(std::string, name, Name);
public:
	PayMethodTypeDO()
	{
		dict_id = -1;
		id = -1;
		name = "";
	}
};



#endif // !SUPPLIERSNAMEDO_H_
