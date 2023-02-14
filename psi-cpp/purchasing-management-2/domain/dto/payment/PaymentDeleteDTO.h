#pragma once

#ifndef _PAYMENTDELETEDTO_H_
#define _PAYMENTDELETEDTO_H_

#include "../../GlobalInclude.h"

/**
 * 删除采购付款申请单
 */
class PaymentDeleteDTO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PaymentDeleteDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, id);
	}
};









#endif // _PAYMENTDELETEDTO_H_