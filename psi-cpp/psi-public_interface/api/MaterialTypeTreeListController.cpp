#include "stdafx.h"
#include"MaterialTypeTreeListController.h"


JsonVO<PageVO<MaterialTypeTreeListVO>> MaterialTypeTreeListController::execMaterialTypeTreeListVO(MaterialTypeItemQuery query) {
    PageVO<MaterialTypeTreeListVO> data(query.getPageIndex(), query.getPageSize(), 100, 10, { MaterialTypeTreeListVO() });
    JsonVO<PageVO<MaterialTypeTreeListVO>> res;
    res.success(data);
    return res;
}