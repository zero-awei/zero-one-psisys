#pragma once

#ifndef _FIN_PAYMENT_REQ_ENTRY_MANAGE_
#define _FIN_PAYMENT_REQ_ENTRY_MANAGE_
#include "../DoInclude.h"

/*
 * 采购付款申请明细管理DO
 */
class FinPaymentReqEntryManageDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
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
	FinPaymentReqEntryManageDO() {
		srcBillType = "";
		srcBillId = "";
		srcEntryId = "";
		srcNo = "";
		amt = 0.00;
		paidAmt = 0.00;
		remark = "";
		custom1 = "";
		custom2 = "";
		version = -1;
	}
};


#endif // !_FIN_PAYMENT_REQ_ENTRY_MANAGE_