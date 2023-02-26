#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_VO_
#define _PREPAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PrepaymentBillVO.h"

/**
 * 示例显示对象
 * 采购预付申请-查询单据列表显示详细信息
 */

class PrepaymentDetailBillVO {
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//业务员
	CC_SYNTHESIZE(string, op, Operator);
	//已付金额
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 已生效
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// 已关闭
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// 已作废
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PrepaymentBillVO, id, bill_no, bill_date, subject, supplier_id, op_dept, op, paid_amt, bill_stage,
		is_effective, is_closed, is_voided, remark);

};
#endif // !_PREPAYMENT_DETAIL_BILL_VO_