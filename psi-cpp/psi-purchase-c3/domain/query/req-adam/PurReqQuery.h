#pragma once
#ifndef _PUR_REQ_QUERY_
#define _PUR_REQ_QUERY_

#include "../PageQuery.h"

/**
 * 示例分页查询对象
 */
class PurReqQuery : public PageQuery
{
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
public:
	// 绑定from_json
	friend void from_json(const json& j, PurReqQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_PUR_REQ_QUERY_