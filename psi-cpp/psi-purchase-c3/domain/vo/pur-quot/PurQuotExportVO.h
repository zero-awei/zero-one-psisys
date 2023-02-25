#pragma once
#ifndef _PUR_QUOT_EXPORT_VO_
#define _PUR_QUOT_EXPORT_VO_

#include "../../GlobalInclude.h"
	
//此VO涉及到数据表中的两个字段pur-quot和pur-quot-entry
//为区分相同的字段, 在pur-quot-entry字段的名字前面加entry前缀
class PurQuotExportVO {
	//是否临时供应商
	CC_SYNTHESIZE(int, is_temp_supplier, is_temp_supplier);
	//供应商名称
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	//交货时间
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//联系人
	CC_SYNTHESIZE(string, contact, Contact);
	//联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	//传真
	CC_SYNTHESIZE(string, fax, Fax);
	//电子邮件
	CC_SYNTHESIZE(string, email, Email);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//金额
	CC_SYNTHESIZE(double, amt, Amt);
	//--------------------明细开始----------------------
	//物料
	CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
	//计量单位
	CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
	//数量
	CC_SYNTHESIZE(double, entry_qty, Entry_qty);
	//税率%
	CC_SYNTHESIZE(double, entry_tax_rate, Entry_tax_rate);
	//含税单价
	CC_SYNTHESIZE(double, entry_price, Entry_price);
	//折扣率%
	CC_SYNTHESIZE(double, entry_discount_rate, Entry_discount_rate);
	//含税金额
	CC_SYNTHESIZE(double, entry_amt, Entry_amt);
	//自定义1
	CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
	//源单分录号---src_no
	CC_SYNTHESIZE(int, entry_src_no, Entry_src_no);
	//分录号2
	CC_SYNTHESIZE(int, entry_entry_no, Entry_entry_no);
	//自定义2
	CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
	//源单分录id
	CC_SYNTHESIZE(string, entry_src_entry_id, Entry_src_entry_id);
	//源单类型
	CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
	//备注
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	//单据编号
	CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
	//源单id
	CC_SYNTHESIZE(int, entry_src_bill_id, Entry_src_bill_id);
	//------------------明细结束-------------------------
	//是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//审批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//已作废
	CC_SYNTHESIZE(int, is_voided, is_voided);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//是否红字
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
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
	BIND_TO_JSON(PurQuotExportVO, is_temp_supplier, supplier_name, supplier_id, payment_method, delivery_place,
		delivery_time, contact, phone, fax, email, qty, amt,
		//明细字段开始
		entry_material_id, entry_unit_id, entry_qty, entry_tax_rate, entry_price, entry_discount_rate, entry_amt,
		entry_custom1, entry_src_no, entry_entry_no, entry_custom2, entry_src_entry_id, entry_src_bill_type, entry_remark, entry_bill_no, entry_src_bill_id,
		//明细字段结束
		is_effective, attachment, src_bill_type, subject, bill_stage, src_no, is_auto, remark,
		bpmi_instance_id, is_voided, bill_no, is_rubric, src_bill_type, create_time, effective_time, approver, update_by,
		sys_org_code, is_closed, approval_result_type, bill_date, create_by, approval_remark);
};

#endif // !
