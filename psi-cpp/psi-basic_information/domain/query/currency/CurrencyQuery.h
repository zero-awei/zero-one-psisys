#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/14 15:30:30
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
#ifndef _CURRENCY_QUERY_
#define _CURRENCY_QUERY_

#include "../PageQuery.h"

/**
 * 基础资料币种模块查询对象
 */
class CurrencyQuery : public PageQuery
{
	// 代码
	CC_SYNTHESIZE(string, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定from_json
	friend void from_json(const json& j, CurrencyQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
	}
};
class OnlyValueCurrencyQuery
{
	CC_SYNTHESIZE(string, id, ID);
public:
	// 绑定from_json
	friend void from_json(const json& j, OnlyValueCurrencyQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};
#endif // !_CURRENCY_QUERY_
