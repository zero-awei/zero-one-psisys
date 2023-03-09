#pragma once
/*
author: qiuqiu
date:2023/2/22
*/


#ifndef PAYMETHODTYPEMAPPER_H_
#define PAYMETHODTYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/PayMethodTypeDO.h"

class PayMethodTypeMapper : public Mapper<PayMethodTypeDO>
{
public:
	PayMethodTypeDO mapper(ResultSet* resultSet) const override
	{
		PayMethodTypeDO data;
		data.setDict_id(resultSet->getUInt64(2));
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !MATERIALTYPEMAPPER_H_
