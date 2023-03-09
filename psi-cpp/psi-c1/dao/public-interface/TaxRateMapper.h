#ifndef _TAXRATE_MAPPER_
#define _TAXRATE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/public-interface/TaxRateDO.h"


class TaxRateMapper : public Mapper<TaxRateDO>
{
public:
	TaxRateDO mapper(ResultSet* resultSet) const override
	{
		TaxRateDO data;

		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_TAXRATE_MAPPER_