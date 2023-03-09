#pragma once
#ifndef _IMPORT_SUPPLIER_DAO_
#define _IMPORT_SUPPLIER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/supplier/ImportSupplierDO.h"

class ImportSupplierDAO : public BaseDAO
{
public:
	// ≤Â»Î ˝æ›
	uint64_t insert(const ImportSupplierDO& iObj);
};
#endif // !_IMPORT_SUPPLIER_DAO_
