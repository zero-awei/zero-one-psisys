#pragma once
/*
author: qiuqiu
date: 2023/2/22
*/
#ifndef MATERIALTYPESERVICE_H_
#define MATERIALTYPESERVICE_H_

#include <list>
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/publicInterfaceVO/PayMethodTypeVO.h"

class PayMethodTypeService
{
public:
	std::list<PayMethodType> listAll();
};



#endif // !MATERIALTYPESERVICE_H_