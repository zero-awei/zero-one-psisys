#include "stdafx.h"
#ifndef __PAY_INTO_DTO_
#define __PAY_INTO_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
//文件上传DTO
class PayIntoDTO : public FileDTO
{
	// 编号
	CC_SYNTHESIZE(int, id, Id);
	//付款类型
	CC_SYNTHESIZE(string, payment_type, Payment_type);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//业务员
	CC_SYNTHESIZE(string, op, Operator);
	//申请金额
	CC_SYNTHESIZE(string, amt, Amt);
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
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);

public:

	friend void from_json(const json& j, PayIntoDTO& t)
	{
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, op_dept);
		BIND_FROM_TO_NORMAL(j, t, op);
		BIND_FROM_TO_D(j, t, payment_type);
		BIND_FROM_TO_NORMAL(j, t, amt);
		BIND_FROM_TO_D(j, t, is_closed);
		BIND_FROM_TO_I(j, t, paid_amt);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_NORMAL(j, t, approval_result_type);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_I(j, t, is_rubric);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, sys_org_code);
	}
};


#endif  //__PURINQUIRYINTODTO_H__
