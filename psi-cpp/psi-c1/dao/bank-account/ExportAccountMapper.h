#pragma once
#ifndef _EXPORTACCOUNTMAPPER_H_
#define _EXPORTACCOUNTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/bank-account/ExportAccountDO.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/22 10:58:22
*/
class ExportAccountMapper : public Mapper<ExportAccountDO>
{
public:
	ExportAccountDO mapper(ResultSet* resultSet) const override
	{
		ExportAccountDO data;
		data.setAccountNo(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setCurrency(resultSet->getString(3));
		data.setInit_bal(resultSet->getDouble(4));
		data.setBankNo(resultSet->getString(5));
		data.setBankAddress(resultSet->getString(6));
		data.setManager(resultSet->getString(7));
		data.setRemark(resultSet->getString(8));
		data.setIsEnabled(resultSet->getInt(9));
		return data;
	}
};

#endif // _EXPORTACCOUNTMAPPER_H_