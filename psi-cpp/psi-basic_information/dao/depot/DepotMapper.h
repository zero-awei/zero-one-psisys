#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _DEPOT_MAPPER_
#define _DEPOT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/depot/DepotDO.h"

/**
 * bas_warehouse表字段匹配映射
 */
class DepotMapper : public Mapper<DepotDO>
{
public:
	DepotDO mapper(ResultSet* resultSet) const override
	{
		DepotDO data;
		// 后面编号要和数据库字段位置对应
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setCode(resultSet->getString(3));
		data.setAuxName(resultSet->getString(4));
		data.setPhone(resultSet->getString(5));
		data.setStart(resultSet->getInt(6));
		data.setRemarks(resultSet->getString(7));
		data.setCreationPeo(resultSet->getString(8));
		data.setCreationTime(resultSet->getString(9));
		data.setModiPeo(resultSet->getString(10));
		data.setModiTime(resultSet->getString(11));
		return data;
	}
};

#endif // !_DEPOT_MAPPER_
