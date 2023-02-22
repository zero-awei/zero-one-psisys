#pragma once
/*
author: qiuqiu
*/

#ifndef PAYMETHODTYPEDAO_H_
#define PAYMETHODTYPEDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/PayMethodTypeDO.h"

class PayMethodTypeDAO : BaseDAO
{
public:
	list<PayMethodTypeDO> SelectMaterialType(const string&);
};
#endif
