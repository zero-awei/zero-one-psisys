#pragma once
#ifndef _PREPAYMENT_VO_
#define _PREPAYMENT_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 * 采购预付申请-添加修改预付申请-输出对象
 */
class PrepaymentVO
{
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

	// 申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// 附件备注
	CC_SYNTHESIZE(string, at_remark, At_remark);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);

	//------------------需要修改------------------------
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PrepaymentVO, bill_no, bill_date, subject, op, op_dept, supplier_id, amt, custom1, custom2, at_remark, attachment, bill_stage, is_effective, is_closed, is_voided);
};

#endif // !_PREPAYMENT_VO_