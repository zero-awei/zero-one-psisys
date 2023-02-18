#pragma once

#ifndef _QueryQtrkBillList_QUERY_
#define _QueryQtrkBillList_QUERY_

#include "../PageQuery.h"

/**
 * 查询单据列表分页查询对象
 */
class QueryQtrkBillListQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// 绑定from_json
	friend void from_json(const json& j, QueryQtrkBillListQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_ULL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_QueryQtrkBillList_QUERY_