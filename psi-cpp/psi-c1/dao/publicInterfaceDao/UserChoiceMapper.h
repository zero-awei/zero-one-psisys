#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author:yunjj
 @Date: 2023/2/20 20:51

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

#ifndef _USERCHOICEMAPPER_H_
#define _USERCHOICEMAPPER_H_

#include "Mapper.h"

class UserChoiceMapper :public Mapper<UserChoiceReturnDO>
{
public:
	UserChoiceReturnDO mapper(ResultSet* resultSet) const override
	{
		UserChoiceReturnDO data;
		data.setId(resultSet->getString(1));
		data.setUserName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setPhone(resultSet->getString(4));
		data.setDepartMent(resultSet->getString(5));
		return data;
	}
};

#endif // _USERCHOICEMAPPER_H_
