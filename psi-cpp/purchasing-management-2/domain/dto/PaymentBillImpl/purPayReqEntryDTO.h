#pragma once

#ifndef _PUR_PAY_REQ_ENTRY_DTO_
#define _PUR_PAY_REQ_ENTRY_DTO_

#include "../../GlobalInclude.h"

class PurPayReqEntryDTO
{
	//分录号
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//源单分录号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PurPayReqEntryDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);
		BIND_FROM_TO_NORMAL(j, t, srcEntryId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);

		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, paidAmt);

		BIND_FROM_TO_I(j, t, entryNo);
	
	}
};

#endif // _PUR_PAY_REQ_ENTRY_DTO_