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
	CC_SYNTHESIZE(std::string, id, ID);
	CC_SYNTHESIZE(std::string, name, Name);
public:
	BIND_TO_JSON(MaterialType, id, name);
};


#endif // !MATERIAL_TYPE_H_



