#pragma once

/*
author: qiuqiu
date:2023/2/22
*/
#ifndef SUPPLIERSNAMEDO_H_
#define SUPPLIERSNAMEDO_H_
#include "../DoInclude.h"

class SuppliersNameDO
{
	CC_SYNTHESIZE(uint64_t, id, ID);
	CC_SYNTHESIZE(std::string, name, Name);

public:
	SuppliersNameDO()
	{
		id = -1;
		name = "";
	}
};


#endif // !SUPPLIERSNAMEDO_H_

