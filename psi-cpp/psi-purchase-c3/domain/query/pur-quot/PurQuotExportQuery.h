#pragma once
#ifndef _PUR_QUOT_EXPORT_QUERY_
#define _PUR_QUOT_EXPORT_QUERY_

#include "../PageQuery.h"

class PurQuotExportQuery : public PageQuery {
	//指定的单据号
	CC_SYNTHESIZE(string, id, ID);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurQuotExportQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_ULL(j, t, id);
	}
};

#endif // !




