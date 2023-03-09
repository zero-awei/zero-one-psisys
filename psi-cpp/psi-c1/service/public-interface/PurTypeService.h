#ifndef _PURTYPE_SERVICE_
#define _PURTYPE_SERVICE_

#include<list>
#include "../../domain/vo/public-interface/PurTypeVO.h"

class PurTypeService
{
public:
	//查询采购方式列表
	list<PurTypeVO> listAll();
};

#endif // !_PURTYPE_SERVICE_

