#pragma once
/* @Author: kiva
 @Date: 2022/10/25 14:21:55
 */
#ifndef _BASBANKACCOUNTMAPPER_H_
#define _BASBANKACCOUNTMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/public-interface/BasBankAccountDO.h"

class BasBankAccountMapper : public Mapper<BasBankAccountDO> {
public:
	BasBankAccountDO mapper(ResultSet* resultSet) const override
	{
		BasBankAccountDO data;
		data.setId(resultSet->getString(1));
		data.setValue(resultSet->getString(2));
		return data;
	}
};
#endif