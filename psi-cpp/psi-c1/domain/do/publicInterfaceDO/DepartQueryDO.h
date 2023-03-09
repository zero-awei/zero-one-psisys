#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/18 13:38

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

#ifndef _DEPARTQUERYDO_H_
#define _DEPARTQUERYDO_H_

#include "../DoInclude.h"

class DepartQueryDO
{
	//要查询部门的名字
	CC_SYNTHESIZE(std::string, departname, DepartName);
	//要查询部门的id
	CC_SYNTHESIZE(std::string, id, Id);
public:
	DepartQueryDO()
	{
		departname = "";
		id = "";
	}
};

#endif // _DEPARTQUERYDO_H_