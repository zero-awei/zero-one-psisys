#include "stdafx.h"
#ifndef __Pur_Quot_FindDetailBill_QUERY_H__
#define __Pur_Quot_FindDetailBill_QUERY_H__

#include "../PageQuery.h"

class PurQuotFindDetailBillQuery
{

	// µ¥¾Ý±àºÅ
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
public:
	friend void from_json(const json& j, PurQuotFindDetailBillQuery& t) {

		BIND_FROM_TO_NORMAL(j, t, receiptId);
	}
};
#endif