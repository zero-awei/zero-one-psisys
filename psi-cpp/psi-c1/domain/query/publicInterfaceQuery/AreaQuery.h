#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/11 13:40

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
#ifndef _AREAQUERY_H_
#define _AREAQUERY_H_

#include "../../GlobalInclude.h"

/*
* 查询某个区域的下辖区域的对象 用于选择区域
*/

class AreaQuery
{
	//需要查询下辖区的区域
	CC_SYNTHESIZE(std::string, areaname, AreaName);
	//需要查询下辖区的区域id
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// 绑定from_json
	friend void from_json(const json& j, AreaQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, areaname);
		BIND_FROM_TO_ULL(j, t, id);
	}
};

#endif // _AREAQUERY_H_