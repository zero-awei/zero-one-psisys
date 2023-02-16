#pragma once
#ifndef _PREPAYMENT_INTO_VO_
#define _PREPAYMENT_INTO_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 * 采购预付申请-导入预付申请单
 */
class PrepayaymentIntoVO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	//付款类型
	CC_SYNTHESIZE(int, payment_type, Payment_type);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//业务员
	CC_SYNTHESIZE(string, op, Operator);
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	//已作废
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	//是否生效
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//是否自动生成
	CC_SYNTHESIZE(bool, is_auto, Is_auto);
	//是否红字
	CC_SYNTHESIZE(bool, is_rubric, Is_rubric);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//已关闭
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);


public:
	BIND_TO_JSON(PrepayaymentIntoVO, id, payment_type, supplier_id,
		op_dept, op, amt, paid_amt, remark, bill_no, approval_result_type, update_by,
		is_effective, is_voided, approver, bill_date,
		is_auto, is_rubric, sys_org_code, create_time, create_by, effective_time,
		bill_stage, is_closed);
};
#endif // !_PREPAYMENT_INTO_VO_
