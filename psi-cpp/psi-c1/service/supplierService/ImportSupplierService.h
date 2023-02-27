#pragma once
#ifndef _IMPORT_SUPPLIER_SERVICE_
#define _IMPORT_SUPPLIER_SERVICE_
#include "../../dao/supplierDAO/ImportSupplierDAO.h"
#include "../../domain/dto/FileDTO.h"

class ImportSupplierService
{
public:
	uint64_t saveData(const FileDTO& dto);

};
#endif // !_IMPORT_SUPPLIER_SERVICE_
