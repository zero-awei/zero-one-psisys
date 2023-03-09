#ifndef _TAXSCALE_MAPPER_
#define _TAXSCALE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/TaxScaleDO.h"


class TaxScaleMapper : public Mapper<TaxScaleDO>
{
public:
	TaxScaleDO mapper(ResultSet* resultSet) const override
	{
		TaxScaleDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // _TAXSCALE_MAPPER_