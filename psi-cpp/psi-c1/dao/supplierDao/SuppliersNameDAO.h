#pragma once
/*
author: qiuqiu
date: 2023/2/22
*/

#ifndef SUPPLIERSNAMEDAO_H_
#define SUPPLIERSNAMEDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/SuppliersNameDO.h"

class SuppliersNameDAO : BaseDAO
{
public:
	list<SuppliersNameDO> SelectMaterialType();
};


#endif // !SUPPLIERSNAMEDAO_H_
