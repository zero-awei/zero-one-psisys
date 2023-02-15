#pragma once
#ifndef _IMPORT_SUPPLIER_CONTROLLER_
#define _IMPORT_SUPPLIER_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/FileDTO.h"

class ImportSupplierController
{
public:
	CREATE_API_FUN_BODY_FILE(importSupplier, execImportSupplier, FileDTO);
private:
	JsonVO<bool> execImportSupplier(const FileDTO& dto);
};

#endif // !_IMPORT_SUPPLIER_CONTROLLER_
