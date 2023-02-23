#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: douhao
 @Date: 2022/10/25 14:21:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CURRENCY_MAPPER_
#define _CURRENCY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/currency/CurrencyDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CurrencyMapper : public Mapper<CurrencyDO>
{
public:
	CurrencyDO mapper(ResultSet* resultSet) const override
	{
		CurrencyDO data;
		data.setId(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setIsFunctional(resultSet->getInt(4));
		data.setIsEnabled(resultSet->getInt(5));
		data.setCreateBy(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setUpdateBy(resultSet->getString(8));
		data.setUpdateTime(resultSet->getString(9));
		data.setRemarks(resultSet->getString(10));

		return data;
	}
};

#endif // !_CURRENCY_MAPPER_
