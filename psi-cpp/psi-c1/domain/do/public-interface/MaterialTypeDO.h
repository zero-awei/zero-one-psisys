#pragma once
/*
Author: qiuqiu
Date: 2023/2/18
*/

#ifndef MATERIALTYPEDO_H_
#define MATERIALTYPEDO_H_

#include "../DoInclude.h"

class MaterialTypeDO
{
	CC_SYNTHESIZE(uint64_t, id, ID);
	CC_SYNTHESIZE(uint64_t, pid, PID);
	CC_SYNTHESIZE(bool, has_child, Has_Child);
	CC_SYNTHESIZE(std::string, name, Name);
public:
	MaterialTypeDO()
	{
		id = -1;
		pid = -1;
		has_child = false;
		name = "";
	}
};




#endif
