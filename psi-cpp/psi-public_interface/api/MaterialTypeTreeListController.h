#pragma once

#ifndef _MATERIALTYPETREELISTCONTROLLER_H_
#define _MATERIALTYPETREELISTCONTROLLER_H_
#include"../domain/vo/PageVO.h"
#include"../domain/vo/MaterialTypeTreeListVO.h"
#include"../domain/vo/JsonVO.h"
#include"../domain/query/MaterialTypeItemQuery.h"

class MaterialTypeTreeListController{

public:
	CREATE_API_FUN_QUERY(queryMaterialTypeTreeList, execMaterialTypeTreeListVO, MaterialTypeItemQuery);

	static map<string, int> ma;
private:
	JsonVO<PageVO<MaterialTypeTreeListVO>> execMaterialTypeTreeListVO(MaterialTypeItemQuery query);
	
};

#endif