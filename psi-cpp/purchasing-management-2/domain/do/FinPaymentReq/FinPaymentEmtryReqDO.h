#pragma once

#ifndef _FIN_PAYMENT_ENTRY_REQ_DO_
#define _FIN_PAYMENT_ENTRY_REQ_DO_
#include "../DoInclude.h"

class FINRaymentEntryReqDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	//单据号
	CC_SYNTHESIZE(string, billNo, BillNo);
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
	CC_SYNTHESIZE(double, amt, amt);
	//已付金额
	CC_SYNTHESIZE(double, paidAmt, paid_amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	FINRaymentEntryReqDO() {

	}
};


#endif; //_FIN_PAYMENT_ENTRY_REQ_DO_