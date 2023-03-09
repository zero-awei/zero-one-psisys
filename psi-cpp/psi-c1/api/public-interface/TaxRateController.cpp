#include "stdafx.h"
#include "TaxRateController.h"
#include "../../service/public-interface/TaxRateService.h"

/*
税率下拉列表
Author C1-三木
2023.2.11 21点59分
*/

JsonVO<list<TaxRateVO>> TaxRateController::executequeryTaxRate()
{
    TaxRateService service;
    list<TaxRateVO> data = service.listAll();
    JsonVO<list<TaxRateVO>> res;
    res.success(data);
    return res;
}
