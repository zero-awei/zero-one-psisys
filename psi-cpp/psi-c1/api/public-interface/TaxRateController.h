#ifndef _TAXRATE_CONTROLLER_
#define _TAXRATE_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/public-interface/TaxRateVO.h"
#include "api/ApiHelper.h"

/*
税率下拉列表
Author C1-三木
2023.2.11 20点55分
*/
class TaxRateController
{
public:
	CREATE_API_FUN_QUERY3(queryTaxRate, executequeryTaxRate);
private:
	JsonVO<list<TaxRateVO>> executequeryTaxRate();
};

#endif //_TAXRATE_CONTROLLER_
