#pragma once
#ifndef _MODIFY_PYRK_BILL_STATE_DTO_
#define _MODIFY_PYRK_BILL_STATE_DTO_

#include "../../GlobalInclude.h"

/**
* 修改盘盈入库单据状态传输对象
*/
class ModifyPyrkBillStateDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);
	// 想要修改为哪种状态的编号(1:关闭, 2:作废, 3:反关闭)
	CC_SYNTHESIZE(uint64_t, toState, ToState);
public:
	ModifyPyrkBillStateDTO() {
		id = "PYRK-220801-023";
		toState = 1;
	}
	// 绑定JSON转换方法
	friend void from_json(const json& j, ModifyPyrkBillStateDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_ULL(j, t, toState);
	}

};

#endif // !_MODIFY_PYRK_BILL_STATE_DTO_