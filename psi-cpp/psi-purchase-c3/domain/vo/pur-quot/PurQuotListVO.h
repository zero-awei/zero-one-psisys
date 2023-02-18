#pragma once
#ifndef _PUR_QUOT_LIST_VO_H_
#define _PUR_QUOT_LIST_VO_H_
#include "../../GlobalInclude.h"
class PurQuotListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotListVO, billNo, billDate);

};
#endif