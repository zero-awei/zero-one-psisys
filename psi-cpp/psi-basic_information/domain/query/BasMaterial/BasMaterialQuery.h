#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/15 21.02

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
#ifndef _BASMATERIAL_QUERY_
#define _BASMATERIAL_QUERY_

#include "../PageQuery.h"

/**
 * 物料查询对象
 */
class BasMaterialQuery : public PageQuery
{
	//id
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	//物料分类
	CC_SYNTHESIZE(string, categoryId, CategoryId);
public:
	// 绑定from_json
	friend void from_json(const json& j, BasMaterialQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_ULL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, code);
		BIND_FROM_TO_NORMAL(j, t, categoryId);
	}
};

#endif // !_BASMATERIAL_QUERY_