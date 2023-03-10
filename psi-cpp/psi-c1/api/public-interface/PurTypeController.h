#ifndef _PURTYPE_CONTROLLER_
#define _PURTYPE_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/public-interface/PurTypeVO.h"
/*
采购方式下拉列表
Author C1-三木
2023.2.11 20点54分
*/
class PurTypeController
{
public:
	CREATE_API_FUN_QUERY3(queryPurType, executequeryPurType);
private:
	JsonVO<list<PurTypeVO>> executequeryPurType();
};

#endif //_PURTYPE_CONTROLLER_