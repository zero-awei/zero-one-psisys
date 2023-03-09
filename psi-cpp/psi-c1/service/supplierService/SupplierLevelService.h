#ifndef _SUPPLIERLEVEL_SERVICE_
#define _SUPPLIERLEVEL_SERVICE_

#include <list>
#include "../../domain/vo/supplierVO/SupplierLevelVO.h"

/*
供应商等级下拉列表
Author C1-三木
*/

class SupplierLevelService
{
public:
	list<SupplierLevelVO> listAll();
};
#endif // !_SUPPLIERLEVEL_SERVICE_