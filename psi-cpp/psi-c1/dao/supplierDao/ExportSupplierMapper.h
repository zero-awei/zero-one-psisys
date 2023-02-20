#pragma once
#ifndef _EXPORT_SUPPLIER_MAPPER_
#define _EXPORT_SUPPLIER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/supplierDO/ExportSupplierDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class ExportSupplierMapper : public Mapper<ExportSupplierDO>
{
public:
	ExportSupplierDO mapper(ResultSet* resultSet) const override
	{
		ExportSupplierDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_EXPORT_SUPPLIER_MAPPER_