#pragma once

#ifndef _ModifyQtrkBill_DTO_
#define _ModifyQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * 修改其他入库单传输对象
 */
class ModifyQtrkBillDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ModifyQtrkBillDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
};

#endif // !_ModifyQtrkBill_DTO_