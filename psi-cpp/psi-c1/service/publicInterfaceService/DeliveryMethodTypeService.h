#pragma once
/*
author: qiuqiu
date: 2023/2/19
*/
#ifndef DELIVERYMETHODTYPESERVICE_H_
#define DELIVERYMETHODTYPESERVICE_H_

#include <list>
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/publicInterfaceVO/DeliveryMethodVO.h"

class DeliveryMethodService
{
public:
	std::list<DeliveryMethodType> listAll();
};



#endif