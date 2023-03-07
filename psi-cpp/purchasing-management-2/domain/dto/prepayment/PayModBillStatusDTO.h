#pragma once
#ifndef _PUR_REQ_MOD_BILL_STATUS_DTO_
#define _PUR_REQ_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include <map>

//修改订单状态的DTO 前端需要传递一个单据编号以及状态修改信息
class PayModBillStatusDTO {
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 操作类型(关闭/反关闭/作废)
	CC_SYNTHESIZE(int, opType, OpType);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 是否关闭
	//CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// 是否作废
	//CC_SYNTHESIZE(bool, is_voided, Is_voided);
public:
	enum OPTYPE { CLOSE = 0, UNCLOSE = 1, CANCEL = 2 }; // 操作类型枚举类
	int OPS[3] = {1, 0, 1}; // 操作类型对应操作数
	//绑定JSON转换方法
	friend void from_json(const json& j, PayModBillStatusDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_