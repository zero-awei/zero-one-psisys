#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#include "../../GlobalInclude.h"

class PurQuotFindDetailBillVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotFindDetailBillVO, billNo, billDate, billStage);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_
