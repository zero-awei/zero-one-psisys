#pragma once
#ifndef _PUR_QUOT_FIND_BILL_VO_H_
#define _PUR_QUOT_FIND_BILL_VO_H_
#include "../../GlobalInclude.h"

class PurQuotFindBillVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotFindBillVO, billNo);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_
