#pragma once
#ifndef _PREPAY_DETAIL_BILL_QUERY_
#define _PREPAY_DETAIL_BILL_QUERY_
#include "../PageQuery.h"

/**
 * 采购预付申请-查询指定预付申请单据列表-查询时点击单据编号
*/
class PrepayDetailBillQuery {
	//指定的单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PrepayDetailBillQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};
#endif // !_PREPAY_DETAIL_BILL_QUERY_
