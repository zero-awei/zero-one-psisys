#pragma once
/*
author: qiuqiu
*/

#ifndef DELIVERYMETHODTYPEDAO_H_
#define DELIVERYMETHODTYPEDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/public-interface/DeliveryMethodTypeDO.h"

class DeliveryMethodTypeDAO : BaseDAO
{
public:
	list<DeliveryMethodTypeDO> SelectMaterialType(const string&);
};



#endif // !MATERIALTYPEDTO