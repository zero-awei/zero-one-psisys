#pragma once
#ifndef _PUR_QUOT_EXPORT_QUERY_H_
#define _PUR_QUOT_EXPORT_QUERY_H_

#include "../PageQuery.h"

class PurQuotExportQuery {
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurQuotExportQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};

#endif // !




