#pragma once
/*
author: qiuqiu
*/

#ifndef PAYMETHODTYPEDAO_H_
#define PAYMETHODTYPEDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/public-interface/PayMethodTypeDO.h"

class PayMethodTypeDAO : BaseDAO
{
public:
	list<PayMethodTypeDO> SelectMaterialType(const string&);
};
#endif
