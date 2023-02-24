#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/21 22:46

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
#ifndef _MATERIALMAPPER_H_
#define _MATERIALMAPPER_H_
#include "Mapper.h"

class MaterialMapper :public Mapper<MaterialReturnDO>
{
public:
	MaterialReturnDO mapper(ResultSet* resultSet) const override
	{
		MaterialReturnDO data;
		data.setId(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setAuxName(resultSet->getString(3));
		data.setCategoryId(resultSet->getString(4));
		data.setCategoryIdDictText(resultSet->getString(5));
		data.setModel(resultSet->getString(6));
		data.setUnitIdDictText(resultSet->getString(7));
		data.setPrice(resultSet->getInt(8));
		data.setTaxCode(resultSet->getString(9));
		data.setIsEnabledDictText(resultSet->getString(10));
		data.setRemark(resultSet->getString(11));
		data.setCreateTime(resultSet->getString(12));
		data.setCreateBy(resultSet->getString(13));
		data.setUpdateTime(resultSet->getString(14));
		data.setUpdateBy(resultSet->getString(15));
		return data;
	}
};

#endif // _MATERIALMAPPER_H_