#include "stdafx.h"
#include "BillStageController.h"
#include "../../service/publicInterfaceService/BillStageService.h"
#include "../../domain/vo/publicInterfaceVO/BillStageVO.h"
/*
单据阶段下拉列表
Author C1-三木
*/

JsonVO<list<BillStageVO>> BillStageController::executequeryBillStage()
{
	BillStageService service;
	list<BillStageVO> data = service.listAll();
	JsonVO<list<BillStageVO>> res;
	res.success(data);
	return res;
}
