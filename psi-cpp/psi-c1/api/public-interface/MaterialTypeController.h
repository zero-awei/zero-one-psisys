#pragma once

/*
@Author: qiuqiu
@Date: 2023/2/13
*/

#ifndef MATERIALTYPECONTROLLER_H_
#define MATERIALTYPECONTROLLER_H_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/public-interface/MaterialTypeVO.h"

class MaterialTypeController
{
public:
	CREATE_API_FUN_QUERY3(queryMaterialType, executeQueryMaterialType);
private:
	JsonVO<std::list<MaterialType>> executeQueryMaterialType();
};







#endif // !MATERIALNAME_H_
