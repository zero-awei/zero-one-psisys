#pragma once

#ifndef _MATERIALTYPETREELISTCONTROLLER_H_
#define _MATERIALTYPETREELISTCONTROLLER_H_
#include"../../domain/vo/PageVO.h"
#include"../../domain/vo/publicInterfaceVO/MaterialTypeTreeListVO.h"
#include"../../domain/vo/JsonVO.h"
#include"../../domain/query/publicInterfaceQuery/MaterialTypeItemQuery.h"

class MaterialTypeTreeListController{

public:
	CREATE_API_FUN_QUERY(queryMaterialTypeTreeList, execMaterialTypeTreeListVO, MaterialTypeItemQuery);

	static map<string, int> ma;
private:
	JsonVO<PageVO<MaterialTypeTreeListVO>> execMaterialTypeTreeListVO(MaterialTypeItemQuery query);
	
};

#endif