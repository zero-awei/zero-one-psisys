#pragma once
#ifndef __PAYMENT_CHANGE_DTO_
#define __PAYMENT_CHANGE_DTO_
#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//修改订单状态的DTO 前端需要传递一个单据编号以及状态修改信息
class PaymentChangeDTO {
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 操作类型(关闭/反关闭/作废)
	CC_SYNTHESIZE(int, opType, OpType);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 是否生效
	//CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// 生效时间
	//CC_SYNTHESIZE(string, effective_time, effective_time);
	// 是否关闭
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
public:
	enum OPS { CLOSE, UNCLOSE, CANCEL }; // 操作类型枚举类
	//绑定JSON转换方法
	friend void from_json(const json& j, PaymentChangeDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_