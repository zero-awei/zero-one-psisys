#pragma once
#ifndef _PUR_QUOT_FIND_BILL_VO_H_
#define _PUR_QUOT_FIND_BILL_VO_H_
#include "../../GlobalInclude.h"
class PurQuotFindBillVO 
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//临时供应商名称
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//交货日期
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//金额
	CC_SYNTHESIZE(double, amt, Amt);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
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
	//自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotFindBillVO, bill_no, bill_date, subject, src_no, supplier_id,
		supplier_name, delivery_time, qty, amt, bill_stage, is_effective, is_closed, is_voided,
		payment_method, delivery_place, contact, phone, fax, email, remark, is_auto, is_rubric,
		effective_time, approver, create_time, create_by, sys_org_code, update_time, update_by);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_
