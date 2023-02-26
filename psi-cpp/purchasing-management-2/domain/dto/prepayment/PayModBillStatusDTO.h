#pragma once
#ifndef _PUR_REQ_MOD_BILL_STATUS_DTO_
#define _PUR_REQ_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//修改订单状态的DTO 前端需要传递一个单据编号以及状态修改信息
class PayModBillStatusDTO {
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, effective_time);
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PayModBillStatusDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_