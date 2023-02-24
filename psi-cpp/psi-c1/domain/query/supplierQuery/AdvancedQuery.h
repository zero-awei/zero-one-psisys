#pragma once

#ifndef _ADVANCED_QUERY_
#define _ADVANCED_QUERY_
#include "../../GlobalInclude.h"
#include "../PageQuery.h"

class AdvancedQuerySQLCondition
{
	CC_SYNTHESIZE(string, field, Field);//待查询的字段
	CC_SYNTHESIZE(string, condition, Condition);
	CC_SYNTHESIZE(string, value, Value);
public:
	friend void from_json(const json& j, AdvancedQuerySQLCondition& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, field);
		BIND_FROM_TO_NORMAL(j, t, condition);
		BIND_FROM_TO_NORMAL(j, t, value);
	}
};

class AdvancedQuery:public PageQuery//后期要继承“普通查询”
{
	//获取sql条件的连接条件：and还是or
	CC_SYNTHESIZE(string, rule, Rule);
	CC_SYNTHESIZE(list<AdvancedQuerySQLCondition>, advancedQueryCondition, AdvancedQueryCondition);
public:
	// 绑定from_json
	friend void from_json(const json& j, AdvancedQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, rule);
		BIND_FROM_TO_OBJ(j, t, advancedQueryCondition, list<AdvancedQuerySQLCondition>);
	}
	
};

#endif // !_ADVANCED_QUERY_

