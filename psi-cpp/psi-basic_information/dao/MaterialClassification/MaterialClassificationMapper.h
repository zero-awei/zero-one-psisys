#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/18 22:52:51

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
#ifndef _MATERIALCLASSIFICATION_MAPPER_
#define _MATERIALCLASSIFICATION_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MaterialClassification/MaterialClassificationDO.h"

/**
 * 物料分类表字段匹配映射
 */

//BIND_TO_JSON(ModifyMaterialClassificationVO, name, code,
//	fullname, is_enabled, create_time, create_by, update_time, update_by);

class MaterialClassificationMapper : public Mapper<MaterialClassificationDO> {

public:
	MaterialClassificationDO mapper(ResultSet* resultSet) const override
	{
		MaterialClassificationDO data;
		//
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
		data.setVersion(resultSet->getInt(12));

		//不明白里面的参数表示什么,好像是列号？是dao里面写的sql语句中select后面参数的顺序，所以select语句中的查询顺序应要一致
		return data;
	}
};

#endif // 