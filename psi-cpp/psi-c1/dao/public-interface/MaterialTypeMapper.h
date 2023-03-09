#pragma once


/*
author:qiuqiu
date: 2023/2/19
*/

#ifndef MATERIALTYPEMAPPER_H_
#define MATERIALTYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/public-interface/MaterialTypeDO.h"

class MaterialTypeMapper : public Mapper<MaterialTypeDO>
{
public:
	MaterialTypeDO mapper(ResultSet* resultSet) const override
	{
		MaterialTypeDO data;
		data.setID(resultSet->getUInt64(1));
		data.setPID(resultSet->getUInt64(2));
		data.setHas_Child(resultSet->getBoolean(3));
		data.setName(resultSet->getString(5));
		return data;
	}
};

#endif // !MATERIALTYPEMAPPER_H_
