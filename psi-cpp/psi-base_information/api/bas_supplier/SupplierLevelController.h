#ifndef _SUPPLIERLEVEL_CONTROLLER_
#define _SUPPLIERLEVEL_CONTROLLER_

#include "domain/vo/JsonVO.h"
#include "domain/vo/bas_supplier/SupplierLevelVO.h"
#include "api/ApiHelper.h"

/*
供应商等级下拉列表
Author C1-三木
2023.2.11 21点20分
*/
class SupplierLevelController
{
public:
	CREATE_API_FUN_QUERY3(querySupplierLevel, executequerySupplierLevel);
private:
	JsonVO<list<SupplierLevelVO>> executequerySupplierLevel();
};

#endif //_SUPPLIERLEVEL_CONTROLLER_
