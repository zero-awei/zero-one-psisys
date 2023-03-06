#pragma once
#ifndef _EXPORT_SUPPLIER_CONTROLLER_
#define _EXPORT_SUPPLIER_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/query/supplierQuery/ExportSupplierQuery.h"

class ExportSupplierController
{
public:
	CREATE_API_FUN_JSON_PAYLOAD(exportSupplier, execExportSupplier, list<ExportSupplierQuery>);
private:
	//执行供应商导出
	JsonVO<std::string> execExportSupplier(const list<ExportSupplierQuery>& query, const PayloadDTO& payload);
};

#endif // !_EXPORT_SUPPLIER_CONTROLLER_