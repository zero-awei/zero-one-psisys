#ifndef _TAXRATE_SERVICE_
#define _TAXRATE_SERVICE_

#include<list>
#include "../../domain/vo/public-interface/TaxRateVO.h"

class TaxRateService
{
public:
	//查询税率列表
	list<TaxRateVO> listAll();
};

#endif // !_PURTYPE_SERVICE_

