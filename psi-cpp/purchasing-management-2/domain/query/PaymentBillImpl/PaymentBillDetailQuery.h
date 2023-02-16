#pragma once

#ifndef _PAYMENT_BILL_DETAIL_QUERY_
#define _PAYMENT_BILL_DETAIL_QUERY_

#include "../PageQuery.h"

/*
查询单据列表
*/
class PaymentBillDetailQuery {
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentBillDetailQuery, srcNo, amt, paidAmt, remark, custom1, custom2);
};

#endif