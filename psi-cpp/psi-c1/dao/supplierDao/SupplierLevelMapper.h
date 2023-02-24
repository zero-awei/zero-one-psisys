#ifndef _SUPPLIERLEVEL_MAPPER_
#define _SUPPLIERLEVEL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/supplierDO/SupplierLevelDO.h"


class SupplierLevelMapper : public Mapper<SupplierLevelDO>
{
public:
	SupplierLevelDO mapper(ResultSet* resultSet) const override
	{
		SupplierLevelDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_SUPPLIERLEVEL_MAPPER_