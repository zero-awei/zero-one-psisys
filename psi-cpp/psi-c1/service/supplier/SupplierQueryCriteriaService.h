#ifndef _SUPPLIERQUERYCRITERIA_SERVICE_
#define _SUPPLIERQUERYCRITERIA_SERVICE_

#include <list>
#include "../../domain/vo/supplier/SupplierQueryCriteriaVO.h"

/*
供应商高级查询条件下拉列表
Author C1-三木
*/

class SupplierQueryCriteriaService
{
public:
	list<SupplierQueryCriteriaVO> listAll();
};
#endif // !_SUPPLIERQUERYCRITERIA_SERVICE_