#ifndef _PURTYPE_MAPPER_
#define _PURTYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/public-interface/PurTypeDO.h"


class PurTypeMapper : public Mapper<PurTypeDO>
{
public:
	PurTypeDO mapper(ResultSet* resultSet) const override
	{
		PurTypeDO data;

		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_PURTYPE_MAPPER_