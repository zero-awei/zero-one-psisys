#include "stdafx.h"
#include "TaxRateController.h"

/*
税率
Author C1-三木
2023.2.11 21点59分
*/

JsonVO<list<TaxRateVO>> TaxRateController::executequeryTaxRate()
{
    list<TaxRateVO> data;
    TaxRateVO vo;
    vo.setId(1);
    vo.setRate("0.17");
    data.push_back(vo);
    JsonVO<list<TaxRateVO>> res;
    res.success(data);
    return res;
}
