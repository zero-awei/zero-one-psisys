#include "stdafx.h"
#include "BasWareHouseTreeListController.h"
#include"../../service/public-interface/BasWareHouseTreeService.h"

JsonVO<PageVO<BasWareHouseTreeListVO>> BasWareHouseTreeListController::execBasWareHouseTreeList(BasWareHouseItemQuery query)
{
	BasWareHouseTreeService service;
	//查询数据
	PageVO<BasWareHouseTreeListVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<BasWareHouseTreeListVO>>(result, RS_SUCCESS);
}
