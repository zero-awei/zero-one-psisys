#include "stdafx.h"
#include "../../GlobalInclude.h"

#ifndef _DEL_PUR_QUOT_VO_
#define _DEL_PUR_QUOT_VO_


//删除供应报价单据
class DelPurQuotVO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DelPurQuotVO, billNo);
};


#endif // !_DEL_PUR_QUOT_VO_