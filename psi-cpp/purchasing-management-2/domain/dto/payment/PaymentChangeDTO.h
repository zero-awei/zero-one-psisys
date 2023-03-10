#pragma once
#ifndef _PAYMENT_CHANGE_DTO_
#define _PAYMENT_CHANGE_DTO_
#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include <map>

// 采购付款申请
class PaymentChangeDTO {
	// id编号
	CC_SYNTHESIZE(string, id, Id);
	// 操作数
	CC_SYNTHESIZE(int, opType, OpType);
	// 账单
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 是否生效
	//CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// 生效时间
	//CC_SYNTHESIZE(string, effective_time, effective_time);
	 // 是否关闭
	//CC_SYNTHESIZE(bool, is_closed, Is_closed);
	//  是否作废
	//CC_SYNTHESIZE(bool, is_voided, Is_voided);
public:
	enum OPTYPE { CLOSE = 0, UNCLOSE = 1, CANCEL = 2 }; // 定义枚举操作数
	int OPS[3] = { 1, 0, 1 }; 
	// 绑定JSON
	friend void from_json(const json& j, PaymentChangeDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_