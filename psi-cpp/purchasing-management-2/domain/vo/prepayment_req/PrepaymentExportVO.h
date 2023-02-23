#pragma once
#ifndef _PREPAYMENT_EXPORT_VO_
#define _PREPAYMENT_EXPORT_VO_

#include "../../GlobalInclude.h"
/**
 * 示例显示对象
 * 采购预付申请-导出预付申请单
 */

class PrepaymentExportVO {

	//付款类型
	CC_SYNTHESIZE(int, payment_type, Payment_type);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, od_dept, Od_dept);
	//业务员
	CC_SYNTHESIZE(string, op, Operator);



	//-----------------付款申请单明细字段开始----------------------------
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);

	//-----------------付款申请单明细字段开始----------------------------
	////申请金额
	//CC_SYNTHESIZE(int, amt, Amt);
	////已付金额
	//CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//源单分录号
	CC_SYNTHESIZE(double, src_on, Src_on);
	//分录号
	CC_SYNTHESIZE(double, entry_on, Entry_on);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	///源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//----------------------明细字段结束---------------------------------
	//是否生效
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	////源单id
	//CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//是否自动生成
	CC_SYNTHESIZE(bool, is_auto, Is_auto);
	// 附件备注
	CC_SYNTHESIZE(string, at_remark, At_remark);
	//审批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//已作废
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	////单据编号
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	//是否红字
	CC_SYNTHESIZE(bool, is_rubric, Is_rubric);
	////源单类型
	//CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);

public:
	BIND_TO_JSON(PrepaymentExportVO, payment_type, supplier_id, od_dept, op, amt, paid_amt,
		//付款申请单明细字段开始
		amt, paid_amt, custom1, src_on, entry_on, custom2, src_entry_id, src_bill_type,
		remark, bill_no, src_bill_id,
		//明细字段结束
		is_effective, attachment, src_bill_id, subject, bill_stage, src_no, is_auto, at_remark, bpmi_instance_id,
		is_voided, bill_no, is_rubric, src_bill_type, create_time, effective_time, approver, update_by, sys_org_code,
		is_closed, approval_result_type, bill_date, create_by, approval_remark);
};
#endif // !_PREPAYMENT_EXPORT_VO_