#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_VO_H_
#define _PUR_QUOT_DIVIDED_LIST_VO_H_
#include "../../GlobalInclude.h"
class PurQuotDividedListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotDividedListVO, billNo);

};
#endif