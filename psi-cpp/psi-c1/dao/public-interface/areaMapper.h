#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author:yunjj
 @Date: 2023/2/18 14:23:49

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
#include "Mapper.h"
#include "../../domain/do/public-interface/AreaQueryDO.h"

class AreaMapper :public Mapper<AreaReturnDO>
{
public:
	AreaReturnDO mapper(ResultSet* resultSet) const override
	{
		AreaReturnDO data;
		data.setAreaName(resultSet->getString(1));
		return data;
	}
};