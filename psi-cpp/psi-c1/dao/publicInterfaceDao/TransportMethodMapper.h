/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ����䷽ʽ
 */

#pragma once
#ifndef _TRANSPORTMETHOD_MAPPER_
#define _TRANSPORTMETHOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/TransportMethodDO.h"

class TransportMethodMapper : public Mapper<TransportMethodDO>
{
public:
	TransportMethodDO mapper(ResultSet* resultSet) const override
	{
		TransportMethodDO data;
		data.setId(resultSet->getInt(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_TRANSPORTMETHOD_MAPPER_