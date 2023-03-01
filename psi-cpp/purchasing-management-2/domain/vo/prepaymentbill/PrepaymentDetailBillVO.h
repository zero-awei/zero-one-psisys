#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_VO_
#define _PREPAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 * 采购预付申请-查询单据列表显示详细信息
 */

class PrepaymentDetailBillVO {
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
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
	BIND_TO_JSON(PrepaymentDetailBillVO, id, entry_no, src_no, amt, remark, custom1, custom2);

	PrepaymentDetailBillVO(){
		amt = 0;
	}
};
#endif // !_PREPAYMENT_DETAIL_BILL_VO_