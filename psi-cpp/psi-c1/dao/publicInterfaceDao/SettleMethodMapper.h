/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * 接口：结算方式
 */

#pragma once
#ifndef _SETTLEMETHOD_MAPPER_
#define _SETTLEMETHOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/SettleMethodDo.h"

class SettleMethodMapper : public Mapper<SettleMethodDO>
{
public:
	SettleMethodDO mapper(ResultSet* resultSet) const override
	{
		SettleMethodDO data;
		data.setId(resultSet->getInt(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_SETTLEMETHOD_MAPPER_