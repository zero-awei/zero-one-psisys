#pragma once

#ifndef _BASWAREHOUSETREELISTCONTROLLER_H_
#define _BASWAREHOUSETREELISTCONTROLLER_H_
#include"../../domain/vo/PageVO.h"
#include"../../domain/vo/public-interface/BasWareHouseTreeListVO.h"
#include"../../domain/vo/JsonVO.h"
#include"../../domain/query/public-interface/BasWareHouseItemQuery.h"

class BasWareHouseTreeListController {

public:
	CREATE_API_FUN_QUERY(queryBasWareHouseTreeList, execBasWareHouseTreeList, BasWareHouseItemQuery);

private:
	JsonVO<PageVO<BasWareHouseTreeListVO>> execBasWareHouseTreeList(BasWareHouseItemQuery query);

};

#endif