#pragma once
/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * 接口：银行账户普通查询
 */

#ifndef _BANKACCOUNT_MAPPER_
#define _BANKACCOUNT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/bankAccount/BankAccountDO.h"

/**
 * 示例表字段匹配映射
 */
class BankAccountMapper : public Mapper<BankAccountDO>
{
public:
	BankAccountDO mapper(ResultSet* resultSet) const override
	{
		BankAccountDO data;
		data.setAccountNo(resultSet->getString(1));
		data.setBankAddress(resultSet->getString(2));
		data.setBankNo(resultSet->getString(3));
		data.setCreateBy_dictText(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setCurrency_dictText(resultSet->getString(6));
		data.setIsEnabled_dictText(resultSet->getUInt64(7));
		data.setManager_dictText(resultSet->getString(8));
		data.setName(resultSet->getString(9));
		data.setRemark(resultSet->getString(10));
		data.setUpdateBy(resultSet->getString(11));
		data.setUpdateTime(resultSet->getString(12));
		return data;
	}
};

#endif // !_BANKACCOUNT_MAPPER_