#pragma once
#ifndef _WAREHOUSE_SERVICE_
#define _WAREHOUSE_SERVICE_

#include <list>
#include "../../domain/query/supplier/ExportSupplierQuery.h"
#include "../../domain/do/supplier/ExportSupplierDO.h"

class ExportSupplierService
{
public:
	//查询要导出的供应商数据
	list<list<ExportSupplierDO>> listAll(const list<ExportSupplierQuery>& query);
};
#endif // !_WAREHOUSE_SERVICE_