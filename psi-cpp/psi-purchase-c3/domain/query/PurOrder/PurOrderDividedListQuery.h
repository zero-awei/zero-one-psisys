#pragma once
/*
* @author:akun
* @time: 2023-2-26 22:06 
*/
#ifndef _PUR_ORDER_DIVIDED_LIST_QUERY_H_
#define _PUR_ORDER_DIVIDED_LIST_QUERY_H_
#include "../../GlobalInclude.h"
/**
 * 采购订单--采购申请的分录列表
 */
class PurOrderDividedListQuery {
	CC_SYNTHESIZE(string, bill_no, BillNo);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurOrderDividedListQuery& t) {
		// 单据编号
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};
#endif // !_PUR_ORDER_QUERY_




