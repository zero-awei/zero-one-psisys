#include "stdafx.h"
#include "BasWareHouseTreeListController.h"

JsonVO<PageVO<BasWareHouseTreeListVO>> BasWareHouseTreeListController::execBasWareHouseTreeList(BasWareHouseItemQuery query)
{
    PageVO<BasWareHouseTreeListVO> data(query.getPageIndex(), query.getPageSize(), 100, 10, { BasWareHouseTreeListVO() });
    JsonVO<PageVO<BasWareHouseTreeListVO>> res;
    res.success(data);
    return res;
}
