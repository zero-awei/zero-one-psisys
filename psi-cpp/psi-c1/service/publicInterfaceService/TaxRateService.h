#ifndef _TAXRATE_SERVICE_
#define _TAXRATE_SERVICE_

#include<list>
#include "../../domain/vo/publicInterfaceVO/TaxRateVO.h"

class TaxRateService
{
public:
	//��ѯ˰���б�
	list<TaxRateVO> listAll();
};

#endif // !_PURTYPE_SERVICE_
