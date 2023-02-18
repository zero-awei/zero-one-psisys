#pragma once
#ifndef _PUR_REQ_MOD_BILL_STATUS_DTO_
#define _PUR_REQ_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//修改订单状态的DTO 前端需要传递一个单据编号以及状态修改信息
class PayModBillStatusDTO {
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PayModBillStatusDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_