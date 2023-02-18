#pragma once
#ifndef _PREPAYMENT_BILL_VO_
#define _PREPAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 * 采购预付申请-查询单据列表显示信息
 */
class PrepaymentBillVO
{
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, od_dept, Od_dept);
	//业务员
	CC_SYNTHESIZE(string, op, Operator);
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
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
	// 生效时间
	CC_SYNTHESIZE(int, effective_time, Effective_time);
	// 核批人
	CC_SYNTHESIZE(string, approver, approver);
	// 制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PrepaymentBillVO, bill_no, bill_date, subject, supplier_id, od_dept, op, amt, paid_amt, bill_stage,
		is_effective, is_closed, is_voided, remark, effective_time, approver, create_time, create_by, sys_org_code, update_time, update_by);
public:
	PrepaymentBillVO() {
		bill_no = "test";
		bill_date = "test";
	}
};
#endif // !_PREPAYMENT_BILL_VO_