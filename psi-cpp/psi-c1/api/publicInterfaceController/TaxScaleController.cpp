#include "stdafx.h"
#include "TaxScaleController.h"
#include "../../service/publicInterfaceService/TaxScaleService.h"

/*
纳税规模下拉列表
Author C1 - 三木
*/

JsonVO<list<TaxScaleVO>> TaxScaleController::executequeryTaxScale()
{
    TaxScaleService service;
    list<TaxScaleVO> data = service.listAll();
    JsonVO<list<TaxScaleVO>> res;
    res.success(data);
    return res;
}
