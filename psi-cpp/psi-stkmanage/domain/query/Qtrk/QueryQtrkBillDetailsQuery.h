#pragma once

#ifndef _QUERYQTRKBILLDETAILS_QUERY_
#define _QUERYQTRKBILLDETAILS_QUERY_

#include "../PageQuery.h"

/**
 * 查询单据列表详细信息分页查询对象
 */
class QueryQtrkBillDetailsQuery 
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// 绑定from_json
	friend void from_json(const json& j, QueryQtrkBillDetailsQuery& t) { // NOLINT

		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_QUERYQTRKBILLDETAILS_QUERY_