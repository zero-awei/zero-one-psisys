#include "stdafx.h"
#include "BillStageController.h"
#include "../../service/public-interface/BillStageService.h"
#include "../../domain/vo/public-interface/BillStageVO.h"
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
