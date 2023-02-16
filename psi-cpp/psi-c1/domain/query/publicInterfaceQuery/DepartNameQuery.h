#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/13 16:18

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
#ifndef _DEPARTNAMEQUERY_H_
#define _DEPARTNAMEQUERY_H_
#include "../../GlobalInclude.h"

class DepartNameQuery
{
    //要查询部门的名字
    CC_SYNTHESIZE(std::string, departname, DepartName);
    //要查询部门的id
    CC_SYNTHESIZE(uint64_t, id, Id);
public:
	friend void from_json(const json& j, DepartNameQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, departname);
		BIND_FROM_TO_ULL(j, t, id);
	}
};

#endif // _DEPARTNAMEQUERY_H_