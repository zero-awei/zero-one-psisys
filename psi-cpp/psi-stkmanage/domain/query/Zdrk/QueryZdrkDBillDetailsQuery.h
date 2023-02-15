#pragma once
#ifndef _QUERYZDRKBILLDETAILS_QUERY_
#define _QUERYZDRKBILLDETAILS_QUERY_

#include "../PageQuery.h"

/**
 * 查询单据详细信息
 */
class QueryZdrkBillDetailsQuery
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// 绑定from_json
	friend void from_json(const json& j, QueryZdrkBillDetailsQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_QUERYDOC_QUERY_