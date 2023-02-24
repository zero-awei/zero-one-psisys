#pragma once
/*
author: qiuqiu
date: 2023/2/22
*/

#ifndef SUPPLIERSNAMESERVICE_H_
#define SUPPLIERSNAMESERVICE_H_

#include <list>
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/supplierVO/SuppliersNameVO.h"


class SuppliersNameService
{
public:
	std::list<SuppliersName> listAll();
};



#endif // !SUPPLIERSNAMESERVICE_H_
