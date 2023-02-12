#pragma once

#ifndef _ACCOUNTQUERY_H_
#define _ACCOUNTQUERY_H_
#include "../PageQuery.h"

/*
* 账户列表查询
* @Author: Oxygen
* @Date: 2023/2/12 14:13:32
*/
class AccountQuery : PageQuery
{
	// 编号
	CC_SYNTHESIZE(string, _t, _t);
	// 列名
	CC_SYNTHESIZE(string, column, Column);
	// 排序规则
	CC_SYNTHESIZE(string, order, Order);
	// 查询范围
	CC_SYNTHESIZE(string, field, Field);
	// 当前页数
	CC_SYNTHESIZE(int, pageNo, PageNo);
	// 页的大小
	CC_SYNTHESIZE(int, PageSizepageSizeNo);
public:
	// 绑定from_json
	friend void from_json(const json& j, AccountQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageNo);
		BIND_FROM_TO_ULL(j, t, pageSizepageSizeNo);
		BIND_FROM_TO_NORMAL(j, t, _t);
		BIND_FROM_TO_NORMAL(j, t, column);
		BIND_FROM_TO_NORMAL(j, t, order);
		BIND_FROM_TO_NORMAL(j, t, field);
	}
};

#endif // _ACCOUNTQUERY_H_