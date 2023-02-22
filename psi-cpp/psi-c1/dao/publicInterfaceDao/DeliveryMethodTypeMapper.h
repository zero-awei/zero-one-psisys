#pragma once
/*
author: qiuqiu
date:2023/2/22
*/


#ifndef DELIVERYMETHODTYPEMAPPER_H_
#define DELIVERYMETHODTYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/DeliveryMethodTypeDO.h"

class DeliveryMethodTypeMapper : public Mapper<DeliveryMethodTypeDO>
{
public:
	DeliveryMethodTypeDO mapper(ResultSet* resultSet) const override
	{
		DeliveryMethodTypeDO data;
		data.setDict_id(resultSet->getUInt64(2));
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !MATERIALTYPEMAPPER_H_
