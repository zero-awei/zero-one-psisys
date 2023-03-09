#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _QUERY_CGRK_BILL_CONDITIONS_QUERY_
#define _QUERY_CGRK_BILL_CONDITIONS_QUERY_

#include "../PageQuery.h"

class QueryCgrkBillConditionsQuery : public PageQuery
{
	//条件字段
	CC_SYNTHESIZE(string, field, Field);
	//条件运算符
	CC_SYNTHESIZE(string, sign, Sign);
	//条件值
	CC_SYNTHESIZE(string, value, Value);
public:
	// 绑定from_json
	friend void from_json(const json& j, QueryCgrkBillConditionsQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, field);
		BIND_FROM_TO_NORMAL(j, t, sign);
		BIND_FROM_TO_NORMAL(j, t, value);
	}
};

#endif // _QUERY_CGRK_BILL_CONDITIONS_QUERY_