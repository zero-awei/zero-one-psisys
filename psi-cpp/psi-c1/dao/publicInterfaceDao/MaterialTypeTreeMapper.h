#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kiva
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
#ifndef _MATERIALTYPETREEMAPPER_H_
#define _MATERIALTYPETREEMAPPER_H_
#include "Mapper.h"
#include"../../domain/do/publicInterfaceDO/MaterialTypeTreeDO.h"
class MaterialTypeTreeMapper : public Mapper<MaterialTypeTreeDO> {
public:
	MaterialTypeTreeDO mapper(ResultSet* resultSet) const override
	{
		MaterialTypeTreeDO data;
		data.setId(resultSet->getString(1));
		data.setPid(resultSet->getString(2));
		data.setHasChild(resultSet->getString(3));
		data.setCode(resultSet->getString(4));
		data.setName(resultSet->getString(5));
		data.setFullname(resultSet->getString(6));
		data.setIsEnabled(resultSet->getInt(7));
		data.setCreateBy(resultSet->getString(8));
		data.setCreateTime(resultSet->getString(9));
		data.setUpdateBy(resultSet->getString(10));
		data.setUpdateTime(resultSet->getString(11));
		data.setVersion(resultSet->getString(12));
		return data;
	}
};

#endif
