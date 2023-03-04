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
#ifndef _QUERY_CGRK_BILL_LIST_ADVANCED_QUERY_
#define _QUERY_CGRK_BILL_LIST_ADVANCED_QUERY_

#include "../PageQuery.h"
#include "QueryCgrkBillConditionsQuery.h"


class Conditions
{
	//条件字段
	CC_SYNTHESIZE(string,field , Field);
	//运算符
	CC_SYNTHESIZE(string, operator1 , Operator1);
	//值
	CC_SYNTHESIZE(string, value, Value);
public:
	// 绑定from_json
	friend void from_json(const json& j, Conditions& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, field);
		BIND_FROM_TO_NORMAL(j, t, operator1);
		BIND_FROM_TO_NORMAL(j, t, value);
	}
};

class QueryCgrkBillListAdvancedQuery : public PageQuery
{
	//逻辑
	CC_SYNTHESIZE(string, logic, Logic);
	//条件列表
	CC_SYNTHESIZE(list<Conditions>, conditionsList, ConditionsList);

public:
	// 绑定from_json
	friend void from_json(const json& j, QueryCgrkBillListAdvancedQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, logic);
		BIND_FROM_TO_OBJ(j, t, conditionsList, list<Conditions>);
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
	}
};

#endif // _QUERY_CGRK_BILL_LIST_ADVANCED_QUERY_