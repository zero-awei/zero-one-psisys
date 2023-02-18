#pragma once
#ifndef _PRE_PAY_DETAIL_BILL_QUERY_
#define _PRE_PAY_DETAIL_BILL_QUERY_
#include "../PageQuery.h"
/*
查询指定单据详细信息
*/
class PrepayDetailBillQuery {
	//指定的单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PrepayDetailBillQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};
#endif // !
