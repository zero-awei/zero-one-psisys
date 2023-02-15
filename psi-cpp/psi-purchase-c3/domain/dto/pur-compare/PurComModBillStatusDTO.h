#ifndef _PUR_COM_MOD_BILL_STATUS_DTO_
#define _PUR_COM_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class PurComModBillStatusDTO{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 已生效
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(int, isClose, Isclose);
	// 已作废
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComModBillStatusDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_I(j, t, isEffect);
		BIND_FROM_TO_I(j, t, isClose);
		BIND_FROM_TO_I(j, t, isCancelled);
	}
};

#endif _

