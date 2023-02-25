
//这个VO作为下面这三个VO的基础部分
//PurQuotFindDetailBillVO
//PurQuotListVO
//PurQuotDividedListVO
#pragma once
#ifndef _PUR_QUOT_BASE_VO_H_
#define _PUR_QUOT_BASE_VO_H_

#include "../../GlobalInclude.h"
class PurQuotBaseVO {

	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//采购询价单

	//是否临时供应商
	CC_SYNTHESIZE(int, is_temp_supplier, Is_temp_supplier);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//临时供应商名称
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//交货日期
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	//联系人
	CC_SYNTHESIZE(string, contact, Contact);
	//联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	//传真
	CC_SYNTHESIZE(string, fax, Fax);
	//电子邮件
	CC_SYNTHESIZE(string, email, Email);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//附件---------------附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//核批结果
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

	//------------前端需要点击按钮才展开的部分
		//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	//自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
public:
	BIND_TO_JSON(PurQuotBaseVO, bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided,
		subject, is_temp_supplier, supplier_id, supplier_name, payment_method, delivery_time, delivery_place,
		contact, phone, fax, email, remark, approval_remark, attachment, approval_result_type, effective_time,
		approver, bpmi_instance_id, bpmi_instance_id, sys_org_code, create_by, update_time, update_by, is_auto, is_rubric, src_bill_type);
};
#endif