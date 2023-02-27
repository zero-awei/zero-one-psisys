#pragma once
#ifndef _INT_MAPPER_
#define _INT_MAPPER_

#include "Mapper.h"

class IntMapper : public Mapper<int>
{
public:
	int mapper(ResultSet* resultSet) const override
	{
		return resultSet->getInt(1);
	}
};

#endif // !_INT_MAPPER_