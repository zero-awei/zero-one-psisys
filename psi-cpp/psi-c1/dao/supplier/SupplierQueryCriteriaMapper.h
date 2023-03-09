#ifndef _SUPPLIERQUERYCRITERIA_MAPPER_
#define _SUPPLIERQUERYCRITERIA_MAPPER_

#include "Mapper.h"
#include "../../domain/do/supplier/SupplierQueryCriteriaDO.h"

/*
供应商高级查询条件下拉列表
Author C1-三木
*/

class SupplierQueryCriteriaMapper : public Mapper<SupplierQueryCriteriaDO>
{
public:
	SupplierQueryCriteriaDO mapper(ResultSet* resultSet) const override
	{
		SupplierQueryCriteriaDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(4));
		return data;
	}
};

#endif // !_SUPPLIERQUERYCRITERIA_MAPPER_