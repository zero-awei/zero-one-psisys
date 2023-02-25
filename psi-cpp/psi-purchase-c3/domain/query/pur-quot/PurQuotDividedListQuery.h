#pragma once
#ifndef __PUR_QUOT_DIVIDED_LIST_QUERY_H_
#define __PUR_QUOT_DIVIDED_LIST_QUERY_H_

#include "../PageQuery.h"

class PurQuotDividedListQuery : public PageQuery{
	//µ¥¾Ý±àºÅ
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	friend void from_json(const json& j, PurQuotDividedListQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};

#endif
