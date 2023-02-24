#pragma once
/*
author: qiuqiu
date: 2023/2/19
*/
#ifndef MATERIALTYPESERVICE_H_
#define MATERIALTYPESERVICE_H_

#include <list>
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/publicInterfaceVO/MaterialTypeVO.h"

class MaterialTypeService
{
public:
	std::list<MaterialType> listAll();
};



#endif // !MATERIALTYPESERVICE_H_
