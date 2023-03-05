/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：运输方式
 */

#pragma once
#ifndef _TRANSPORTMETHOD_MAPPER_
#define _TRANSPORTMETHOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/TransportMethodDo.h"

class TransportMethodMapper : public Mapper<TransportMethodDO>
{
public:
	TransportMethodDO mapper(ResultSet* resultSet) const override
	{
		TransportMethodDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_TRANSPORTMETHOD_MAPPER_