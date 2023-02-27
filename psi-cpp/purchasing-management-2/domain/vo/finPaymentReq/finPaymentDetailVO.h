#pragma once

#ifndef _FIN_PAYMENT_DETAIL_VO_
#define _FIN_PAYMENT_DETAIL_VO_

#include "../../GlobalInclude.h"
#include "finPaymentReqVO.h"
#include "finPaymentReqEntryVO.h"

/*
查询单据列表显示对象
*/
//备注:类的宏里面的字段类型需要更改
class FinPaymentDetailVO : public FinPaymentReqVO {
	//明细列表
	CC_SYNTHESIZE(list<FinPaymentReqEntryVO>, detailBillsVO, DetailBillsVO);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(FinPaymentDetailVO, billNo, billDate, isEffective, isClosed,
		isVoided, subject, detailBillsVO);
};
#endif // _FIN_PAYMENT_DETAIL_VO_
