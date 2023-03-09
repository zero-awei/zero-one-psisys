#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/13 16:03

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
#ifndef _DEPARTVO_H_
#define _DEPARTVO_H_

#include "../../GlobalInclude.h"

class DepartVO
{
	//部门的名字(公司或者具体部门)
	CC_SYNTHESIZE(std::string, departname, DepartName);
	//部门的id
	CC_SYNTHESIZE(std::string, id, Id);
public:
	DepartVO()
	{
		departname = "";
		id = "";
	}
	BIND_TO_JSON(DepartVO, departname, id);
};

#endif // _DEPARTVO_H_