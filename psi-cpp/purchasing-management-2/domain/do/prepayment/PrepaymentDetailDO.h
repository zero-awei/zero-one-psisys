#pragma once

#ifndef _PREPAYMENTDETAILDO_H_
#define _PREPAYMENTDETAILDO_H_

#include "../DoInclude.h"
/**
 * 示例数据库实体类-采购预付实体类
 */
class PrepaymentDetailDO {
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(uint64_t, entry_no, Entry_no);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcBillId
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(uint64_t, version, Version);

public:
	PrepaymentDetailDO() {
		entry_no = -1;
		amt = 0.00;
		paid_amt = 0.00;
		version = -1;
	}
};
#endif // _PREPAYMENTDETAILDO_H_

