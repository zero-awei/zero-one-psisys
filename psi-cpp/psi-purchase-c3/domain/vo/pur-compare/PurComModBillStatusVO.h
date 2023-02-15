#pragma once

#ifndef _PUR_COM_MOD_BILL_STATUS_VO_
#define _PUR_COM_MOD_BILL_STATUS_VO_
#include "../../GlobalInclude.h"

class PurComModBillStatusVO{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 已生效
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(int, isClose, Isclose);
	// 已作废
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// 单据阶段
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComModBillStatusVO, billId, isEffect, isClose, isCancelled, billStatus, updateDate, updatePerson);
};
#endif