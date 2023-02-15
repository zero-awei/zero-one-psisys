#pragma once
#ifndef _EXPORT_SUPPLIER_CONTROLLER_
#define _EXPORT_SUPPLIER_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/FileDTO.h"

class ExportSupplierController
{
public:
	CREATE_API_FUN_QUERY3(exportSupplier, execExportSupplier);
private:
	//执行供应商导出
	JsonVO<std::string> execExportSupplier();
};

#endif // !_EXPORT_SUPPLIER_CONTROLLER_