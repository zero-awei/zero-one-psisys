#pragma once

/*
author: qiuqiu
date:2023/2/18
*/


#ifndef MATERIALTYPEDAO
#define MATERIALTYPEDAO

#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/MaterialTypeDO.h"

class MaterialTypeDAO : BaseDAO
{
public:
	list<MaterialTypeDO> SelectMaterialType();
};



#endif // !MATERIALTYPEDTO
