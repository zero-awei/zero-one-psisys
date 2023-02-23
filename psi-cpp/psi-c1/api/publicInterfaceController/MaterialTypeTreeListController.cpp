#include "stdafx.h"
#include"MaterialTypeTreeListController.h"
#include"../../service/publicInterfaceService/MaterialTypeTreeService.h"


JsonVO<PageVO<MaterialTypeTreeListVO>> MaterialTypeTreeListController::execMaterialTypeTreeListVO(MaterialTypeItemQuery query) {
	//定义一个Service
	MaterialTypeTreeListService service;
	//查询数据
	PageVO<MaterialTypeTreeListVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<MaterialTypeTreeListVO>>(result, RS_SUCCESS);
}