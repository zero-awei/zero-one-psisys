#pragma once
#ifndef _WAREHOUSE_SERVICE_
#define _WAREHOUSE_SERVICE_

#include <list>
#include "../../domain/query/supplierQuery/ExportSupplierQuery.h"
#include "../../domain/do/supplierDO/ExportSupplierDO.h"

class ExportSupplierService
{
public:
	//查询要导出的供应商数据
	list<ExportSupplierDO> listAll(const ExportSupplierQuery& query);
};
#endif // !_WAREHOUSE_SERVICE_