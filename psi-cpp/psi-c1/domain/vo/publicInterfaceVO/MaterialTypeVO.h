#pragma once

/*
* 物料类型
author: qiuqiu
date: 2023/2/13
*/

#ifndef MATERIAL_TYPE_H_
#define MATERIAL_TYPE_H_

#include "../../GlobalInclude.h"


class MaterialType
{
	CC_SYNTHESIZE(uint64_t, id, ID);
	CC_SYNTHESIZE(uint64_t, pid, PID);
	CC_SYNTHESIZE(bool, has_child, Has_Child);
	CC_SYNTHESIZE(std::string, name, Name);
public:
	BIND_TO_JSON(MaterialType, id, pid, has_child, name);
};


#endif // !MATERIAL_TYPE_H_



