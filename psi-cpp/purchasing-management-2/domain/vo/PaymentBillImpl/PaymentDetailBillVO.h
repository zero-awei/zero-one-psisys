#pragma once

#ifndef _PAYMENT_DETAIL_BILL_VO_
#define _PAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PaymentBillVO.h"
#include "PaymentBillDetailVO.h"

/*
查询单据列表显示对象
*/
//备注:类的宏里面的字段类型需要更改
class PaymentDetailBillVO : public PaymentBillVO {
	//明细列表
	CC_SYNTHESIZE(list<PaymentBillDetailVO>, detailBillsVO, DetailBillsVO);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentDetailBillVO, billNo, billDate, isEffective, isClosed,
		isVoided, subject, detailBillsVO);
};
#endif // _PAYMENT_DETAIL_BILL_VO_
