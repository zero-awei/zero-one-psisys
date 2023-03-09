#pragma once
/*
author:qiuqiu
date: 2023/2/22
*/

#ifndef SUPPLIERSNAMETYPEMAPPER_H_
#define SUPPLIERSNAMETYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/public-interface/SuppliersNameDO.h"


class SuppliersNameMapper : public Mapper<SuppliersNameDO>
{
public:
	SuppliersNameDO mapper(ResultSet* resultSet) const override
	{
		SuppliersNameDO data;
		data.setID(resultSet->getUInt64(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !MATERIALTYPEMAPPER_H_
