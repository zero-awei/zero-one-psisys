#pragma once
#ifndef __PUR_QUOT_LIST_QUERY_H_
#define __PUR_QUOT_LIST_QUERY_H_

#include "../PageQuery.h"

class PurQuotListQuery
{

	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);

public:
	friend void from_json(const json& j, PurQuotListQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);

	}
};
#endif
