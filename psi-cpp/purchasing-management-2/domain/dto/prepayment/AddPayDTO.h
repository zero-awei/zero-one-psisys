#pragma once
#ifndef _ADD_PAY_DTO_
#define _ADD_PAY_DTO_

#include "../../GlobalInclude.h"
#include "AddPayDetailDTO.h"
/**
 * 采购预付申请-添加预付申请-输入对象
 * 付款申请单——fin_payment_req
 */
class AddPayDTO
{
	//------------------直接填入------------------------
	// ID
	CC_SYNTHESIZE(string, id, Id);
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
	CC_SYNTHESIZE(string, remark, At_remark);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 明细
	CC_SYNTHESIZE(std::list<AddPayDetailDTO>, detail, Detail);
	//------------------不填入------------------------
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 已生效
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// 已关闭
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// 已作废
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddPayDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, op);
		BIND_FROM_TO_NORMAL(j, t, op_dept);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_OBJ(j, t, detail, std::list<AddPayDetailDTO>);

		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_B(j, t, is_effective);
		BIND_FROM_TO_B(j, t, is_closed);
		BIND_FROM_TO_B(j, t, is_voided);
	}; // NOLINT
	BIND_TO_JSON(AddPayDTO, id, bill_no, bill_date, subject, op, op_dept, supplier_id, remark, attachment, detail, bill_stage, is_effective, is_closed, is_voided);
};

#endif // !_SAMPLE_DTO_