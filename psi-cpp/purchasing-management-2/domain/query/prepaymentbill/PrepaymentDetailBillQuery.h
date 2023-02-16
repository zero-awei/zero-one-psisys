#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_QUERY_
#define _PREPAYMENT_DETAIL_BILL_QUERY_
#include "../PageQuery.h"
/*
查询指定单据详细信息
*/
class PrepaymentDetailBillQuery {
	//指定的单据号
	CC_SYNTHESIZE(string, id, ID);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PrepaymentDetailBillQuery& t) {
	}
};
#endif // !
