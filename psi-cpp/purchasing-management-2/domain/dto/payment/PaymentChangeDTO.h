#pragma once

#ifndef _PAYMENTCHANGEDTO_H_
#define _PAYMENTCHANGEDTO_H_

#include "../../GlobalInclude.h"

/**
 * 修改单据状态（关闭/作废/反关闭）
 */
class PaymentChangeDTO
{
	
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 状态(close/unclose/abolish)
	CC_SYNTHESIZE(string, status, Status);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PaymentChangeDTO& t); // NOLINT
	BIND_TO_JSON(PaymentChangeDTO, id, status);
};

#endif // !_PAYMENTCHANGEDTO_H_