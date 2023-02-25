#pragma once
#ifndef _STRING_MAPPER_
#define _STRING_MAPPER_

#include "Mapper.h"

/*
* ²éÑ¯ÌØ¶¨×Ö·û´®×Ö¶ÎÆ¥ÅäÓ³Éä
*/
class StringMapper : public Mapper<std::string>
{
public:
	std::string mapper(ResultSet* resultSet) const override
	{
		return resultSet->getString(1);
	}
};

#endif // !_STRING_MAPPER_