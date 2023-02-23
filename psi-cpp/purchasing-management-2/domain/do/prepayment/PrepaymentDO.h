#pragma once
#ifndef _PREPAYMENT_DO_
#define _PREPAYMENT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类-采购预付实体类
 */
class PrepaymentDO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
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
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
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
	PrepaymentDO() {
		id = 0;
		bill_no = "";
		bill_date = "";
		subject = "";
		supplier_id = "";
		op_dept = "";
		op = "";
		amt = 0;
	}
};
#endif // !_PREPAYMENT_DO_
