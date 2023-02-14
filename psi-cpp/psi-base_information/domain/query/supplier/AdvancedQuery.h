#pragma once

#ifndef _ADVANCED_QUERY_
#define _ADVANCED_QUERY_
#include "../../GlobalInclude.h"

class AdvancedQuery
{
	// 过滤匹配条件
	CC_SYNTHESIZE(string, rule, Rule);
	//查询字段
	CC_SYNTHESIZE(string, name, Name);
	//	字段查询条件：等于、包含、不等于、大于....
	CC_SYNTHESIZE(string, condition, Condition);
	//用户输入的需要查询的字段的值
	CC_SYNTHESIZE(string, value, Value);
public:
	// 绑定from_json
	friend void from_json(const json& j, AdvancedQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, rule);
		BIND_FROM_TO_ULL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, condition);
		BIND_FROM_TO_NORMAL(j, t, value);
	}
};

#endif // !_ADVANCED_QUERY_

