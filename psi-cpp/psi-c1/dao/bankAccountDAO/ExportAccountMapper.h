#pragma once
#ifndef _EXPORTACCOUNTMAPPER_H_
#define _EXPORTACCOUNTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/bankAccountDO/ExportAccountDO.h"

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
		data.setAccount_no(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // _EXPORTACCOUNTMAPPER_H_