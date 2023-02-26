#pragma once
#ifndef Q_C_B_DO_MAPPER
#define Q_C_B_DO_MAPPER

#include "Mapper.h"
#include "../../domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"

class QueryCgthrkBillListDOMapper : public Mapper<QueryCgthrkBillListReturnDO> {
public:
	QueryCgthrkBillListReturnDO mapper(ResultSet* resultSet) const override
	{
		QueryCgthrkBillListReturnDO data;
		data.setBillNo(resultSet->getString(1));
		//data.setName(resultSet->getString(2));
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getInt(4));
		return data;
	}

};

#endif // !Q_C_B_DO_MAPPER
