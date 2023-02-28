#pragma once
#ifndef _PUR_COM_MOD_BILL_STATUS_DTO_H_
#define _PUR_COM_MOD_BILL_STATUS_DTO_H_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class PurComModBillStatusDTO{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 已生效
	CC_SYNTHESIZE(string, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isCancelled, IsCancelled);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComModBillStatusDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_NORMAL(j, t, isEffect);
		BIND_FROM_TO_NORMAL(j, t, isClose);
		BIND_FROM_TO_NORMAL(j, t, isCancelled);
	}
};

#endif //!_PUR_COM_MOD_BILL_STATUS_DTO_H_

