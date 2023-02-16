#pragma once
#ifndef _PREPAYMENT_ENTRY_DTO_
#define _PREPAYMENT_ENTRY_DTO_

#include "../../GlobalInclude.h"

/**
 * 采购预付申请-添加修改预付申请-引入明细
 * 付款申请单明细——fin_payment_req_entry
 */
class PrepaymentEntryDTO
{

	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 主表
	CC_SYNTHESIZE(string,mid, Mid);
	// 单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(double, entry_on, Entry_on);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(double, src_on, Src_on);
	// 申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	// 已付金额
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PrepaymentEntryDTO& t); // NOLINT
	BIND_TO_JSON(PrepaymentEntryDTO, id, mid, bill_no, entry_on, src_bill_type, src_bill_id, src_entry_id, src_on, amt, paid_amt, remark, custom1, custom2);
};

#endif // !_PREPAYMENT_ENTRY_DTO_
