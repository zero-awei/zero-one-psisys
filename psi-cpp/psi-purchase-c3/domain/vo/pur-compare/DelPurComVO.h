#pragma once
#ifndef _DEL_PUR_COM_VO_
#define _DEL_PUR_COM_VO_
#include "../../GlobalInclude.h"

class DelPurComVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DelPurComVO, billId);
};
#endif