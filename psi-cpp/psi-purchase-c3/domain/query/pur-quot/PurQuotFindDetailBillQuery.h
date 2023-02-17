#pragma once
#ifndef __PUR_QUOT_FIND_DETAIL_QUERY_H_
#define __PUR_QUOT_FIND_DETAIL_QUERY_H_

#include "../PageQuery.h"

class PurQuotFindDetailBillQuery : public PageQuery
{

	// µ¥¾Ý±àºÅ
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
public:
	friend void from_json(const json& j, PurQuotFindDetailBillQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, receiptId);
	}
};
#endif