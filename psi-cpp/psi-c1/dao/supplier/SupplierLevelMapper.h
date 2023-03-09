#ifndef _SUPPLIERLEVEL_MAPPER_
#define _SUPPLIERLEVEL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/supplier/SupplierLevelDO.h"


class SupplierLevelMapper : public Mapper<SupplierLevelDO>
{
public:
	SupplierLevelDO mapper(ResultSet* resultSet) const override
	{
		SupplierLevelDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_SUPPLIERLEVEL_MAPPER_