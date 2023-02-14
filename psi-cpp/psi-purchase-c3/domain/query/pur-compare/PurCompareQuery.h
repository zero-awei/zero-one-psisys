#pragma once
#ifndef _PUR_COMPARE_QUERY_
#define _PUR_COMPARE_QUERY_

#include "../PageQuery.h"

/**
 * 示例分页查询对象
 */
class PurCompareQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 单据开始日期
	CC_SYNTHESIZE(string, billBeginDate, BillBeginDate);
	// 单据结束日期
	CC_SYNTHESIZE(string, billEndDate, BillEndDate);
	// 交付开始日期
	CC_SYNTHESIZE(string, deliveryBeginDate, DeliveryBeginDate);
	// 交付结束日期
	CC_SYNTHESIZE(string, deliveryEndDate, DeliveryEndDate);
	
public:
	// 绑定from_json
	friend void from_json(const json& j, PurCompareQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_NORMAL(j, t, billBeginDate);
		BIND_FROM_TO_NORMAL(j, t, billEndDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryBeginDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryEndDate);
	}
};

#endif // !_PUR_COMPARE_QUERY_