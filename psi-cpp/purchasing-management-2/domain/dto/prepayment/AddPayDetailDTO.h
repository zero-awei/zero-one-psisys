#pragma once

#ifndef _ADDPAYDETAILDTO_H_
#define _ADDPAYDETAILDTO_H_

#include "../../GlobalInclude.h"

/**
 * 采购预付申请-添加预付申请-新增明细
 * 付款申请单明细——fin_payment_req_entry
 */
class AddPayDetailDTO {
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已付金额
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddPayDetailDTO& t) {
		BIND_FROM_TO_I(j, t, entry_no);
		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		BIND_FROM_TO_NORMAL(j, t, src_entry_id);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, paid_amt);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	} // NOLINT
	BIND_TO_JSON(AddPayDetailDTO, entry_no, src_bill_type, src_bill_id, src_entry_id, src_no, amt, paid_amt, remark, custom1, custom2);
};


#endif // _ADDPAYDETAILDTO_H_