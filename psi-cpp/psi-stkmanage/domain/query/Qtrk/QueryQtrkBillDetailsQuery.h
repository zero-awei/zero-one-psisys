#pragma once

#ifndef _QueryQtrkBillDetails_QUERY_
#define _QueryQtrkBillDetails_QUERY_

#include "../PageQuery.h"

/**
 * 查询单据列表详细信息分页查询对象
 */
class QueryQtrkBillDetailsQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);
public:
	// 绑定from_json
	friend void from_json(const json& j, QueryQtrkBillDetailsQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_QueryQtrkBillDetails_QUERY_