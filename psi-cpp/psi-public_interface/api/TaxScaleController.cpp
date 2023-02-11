#include "stdafx.h"
#include "TaxScaleController.h"

/*
纳税规模
Author C1 - 三木
2023.2.11 22点01分
*/

JsonVO<list<TaxScaleVO>> TaxScaleController::executequeryTaxScale()
{
    list<TaxScaleVO> data;
    TaxScaleVO vo;
    vo.setId(1);
    vo.setName(u8"一般纳税人");
    data.push_back(vo);
    JsonVO<list<TaxScaleVO>> res;
    res.success(data);
    return res;
}
