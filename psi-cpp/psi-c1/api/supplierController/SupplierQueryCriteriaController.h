#ifndef _SUPPLIERQUERYCRITERIA_CONTROLLER_
#define _SUPPLIERQUERYCRITERIA_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/supplierVO/SupplierQueryCriteriaVO.h"
#include "api/ApiHelper.h"

/*
供应商高级查询条件下拉列表
Author C1-三木
2023.2.13 21点10分
*/
class SupplierQueryCriteriaController
{
public:
	CREATE_API_FUN_QUERY3(querySupplierQueryCriteria, executequerySupplierQueryCriteria);
private:
	JsonVO<list<SupplierQueryCriteriaVO>> executequerySupplierQueryCriteria();
};

#endif //_SUPPLIERQUERYCRITERIA_CONTROLLER_