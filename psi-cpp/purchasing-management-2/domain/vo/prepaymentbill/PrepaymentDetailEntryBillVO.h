#pragma once
#ifndef _PREPAYMENT_DETAIL_ENTRY_BILL_VO_
#define _PREPAYMENT_DETAIL_ENTRY_BILL_VO_

#include "../../GlobalInclude.h"
/**
 * 示例显示对象
 * 采购预付申请-查询单据列表显示明细
 */

class PrepaymentDetailEntryBillVO {

	//ID
	CC_SYNTHESIZE(string, id, Id);
	//单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PrepaymentDetailEntryBillVO, id, bill_no, entry_no, amt, remark,  custom1, custom2)

};
#endif // !_PREPAYMENT_DETAIL_ENTRY_BILL_VO_