#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/19 14:21:55

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
#ifndef _BASMATERIAL_MAPPER_
#define _BASMATERIAL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/BasMaterial/BasMaterialDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class BasMaterialMapper : public Mapper<BasMaterialDO>
{
public:
	BasMaterialDO mapper(ResultSet* resultSet) const override
	{
		BasMaterialDO data;
		data.setId(resultSet->getString(1));
		data.setCategoryId(resultSet->getString(2));
		data.setCode(resultSet->getString(3));
		data.setName(resultSet->getString(4));
		data.setAuxName(resultSet->getString(5));
		data.setIsEnabled(resultSet->getInt(6));
		data.setModel(resultSet->getString(7));
		data.setUnitId(resultSet->getString(8));
		data.setSalePrice(resultSet->getInt(9));
		data.setTaxCode(resultSet->getString(10));
		data.setRemark(resultSet->getString(11));
		data.setCreateTime(resultSet->getString(12));
		data.setCreateBy(resultSet->getString(13));
		data.setUpdateBy(resultSet->getString(14));
		data.setUpdateTime(resultSet->getString(15));

		return data;
	}
};

#endif // !_BASMATERIAL_MAPPER_