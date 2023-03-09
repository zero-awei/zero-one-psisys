#pragma once

#ifndef _MATERIALTYPETREELISTCONTROLLER_H_
#define _MATERIALTYPETREELISTCONTROLLER_H_
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/public-interface/MaterialTypeTreeListVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/public-interface/MaterialTypeItemQuery.h"

class MaterialTypeTreeListController{

public:
	CREATE_API_FUN_QUERY(queryMaterialTypeTreeList, execMaterialTypeTreeListVO, MaterialTypeItemQuery);

	static map<string, int> ma;
private:
	JsonVO<PageVO<MaterialTypeTreeListVO>> execMaterialTypeTreeListVO(MaterialTypeItemQuery query);
	
};

#endif