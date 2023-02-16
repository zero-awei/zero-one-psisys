#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/13 15:36

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
#ifndef _USERQUERY_H_
#define _USERQUERY_H_

#include "../../GlobalInclude.h"

class UserQuery
{
	//查询用户数据时用的用户账号名称
	CC_SYNTHESIZE(std::string, username, UserName);
public:
	// 绑定from_json
	friend void from_json(const json& j, UserQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, username);
	}
};

#endif // _USERQUERY_H_