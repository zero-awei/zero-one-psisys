#pragma once

#ifndef _PAYMENT_BILL_VO_
#define _PAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/*
查询单据列表
*/
class PaymentBillVO {
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id)
	// 业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept)
	// 业务员
	CC_SYNTHESIZE(string, operator,Operator)
	// 源单号
	CC_SYNTHESIZE(string,src_no,Src_no)
	// 申请金额
	CC_SYNTHESIZE(double, amt, Amt)
	// 已付金额
	CC_SYNTHESIZE(double, paid_amt, Paid_amt)
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭			
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
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
	BIND_TO_JSON(PaymentBillVO, bill_no, bill_date, subject, supplier_id, op_dept,
		operator, src_no, amt, paid_amt, bill_stage,is_effective, is_closed, is_voided,
		is_auto, is_rubric, remark,effective_time,
		approver, create_time, create_by, sys_org_code, update_time, update_by);
};



/*
查询单据列表
*/
class PaymentBillDetailQuery : public PaymentBillVO {
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已付金额
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentBillDetailQuery, src_no, amt, paid_amt, remark, custom1, custom2);
};

#endif