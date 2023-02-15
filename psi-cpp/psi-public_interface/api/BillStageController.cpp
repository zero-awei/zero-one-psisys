#include "stdafx.h"
#include "BillStageController.h"

/*
单据阶段下拉列表
Author C1-三木
2023.2.11 21点42分
*/

JsonVO<list<BillStageVO>> BillStageController::executequeryBillStage()
{
    list<BillStageVO> data;
    BillStageVO vo;
    vo.setId(1);
    vo.setName(u8"审核中");
    data.push_back(vo);
    JsonVO<list<BillStageVO>> res;
    res.success(data);
    return res;
}
