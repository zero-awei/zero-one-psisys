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
		data.setShortName(resultSet->getString(3));
		data.setAuxName(resultSet->getString(4));
		data.setSupplierCategory(resultSet->getString(5));
		data.setSupplierLevel(resultSet->getString(6));
		data.setIsEnabled(resultSet->getInt(7));
		return data;
	}
};

#endif // !_EXPORT_SUPPLIER_MAPPER_