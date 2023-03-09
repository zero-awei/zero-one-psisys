#pragma once
#ifndef _MODIFY_CGRK_BILL_STATE_DTO_
#define _MODIFY_CGRK_BILL_STATE_DTO_

#include "../../GlobalInclude.h"

/**
 * 修改单据状态
 */
class ModifyCgrkBillStateDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ModifyCgrkBillStateDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
	
};

#endif // !_MODIFY_CGRK_BILL_STATE_DTO_