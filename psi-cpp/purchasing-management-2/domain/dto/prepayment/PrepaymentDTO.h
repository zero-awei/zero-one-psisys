#pragma once
#ifndef _PRE_PAYMENT_DTO_
#define _PRE_PAYMENT_DTO_

#include "../../GlobalInclude.h"

/**
 * 采购预付申请-添加修改预付申请-输入对象
 * 付款申请单——fin_payment_req
 */
class PrepaymentDTO
{
	//------------------直接填入------------------------
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 业务员
	CC_SYNTHESIZE(string, op, Operator);
	// 业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// 附件备注
	CC_SYNTHESIZE(string, at_remark, At_remark);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);

	//------------------不填入------------------------
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 已生效
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// 已关闭
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// 已作废
	CC_SYNTHESIZE(bool, is_voided, Is_voided);

	// 主表
	CC_SYNTHESIZE(string, mid, Mid);
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
	friend void from_json(const json& j, PrepaymentDTO& t); // NOLINT
	BIND_TO_JSON(PrepaymentDTO, id, bill_no, bill_date, subject, op, op_dept, supplier_id, at_remark, attachment, bill_stage, is_effective, is_closed, is_voided,
		mid, entry_on, src_bill_type, src_bill_id, src_entry_id, src_on, amt, paid_amt, remark, custom1, custom2);
};

#endif // !_SAMPLE_DTO_