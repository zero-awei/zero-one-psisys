#include "stdafx.h"
#include "PurTypeController.h"

/*
采购方式
Author C1-三木
2023.2.11 21点56分
*/

JsonVO<list<PurTypeVO>> PurTypeController::executequeryPurType()
{
    list<PurTypeVO> data;
    PurTypeVO vo;
    vo.setId(1);
    vo.setName(u8"集中采购");
    data.push_back(vo);
    JsonVO<list<PurTypeVO>> res;
    res.success(data);
    return res;
}
