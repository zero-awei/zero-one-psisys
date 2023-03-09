#pragma once
/*
* 供应商名称下拉列表
* @Author: qiuqiu
* @Date: 2023/2/13
*/

#ifndef SUPPLIERS_NAME_H_
#define SUPPLIERS_NAME_H_

#include "../../GlobalInclude.h"

class SuppliersName
{

	CC_SYNTHESIZE(uint64_t, id, ID);
	CC_SYNTHESIZE(std::string, name, Name);

public:
	BIND_TO_JSON(SuppliersName, id, name);
};





#endif // !SUPPLIERS_NAME_H_





