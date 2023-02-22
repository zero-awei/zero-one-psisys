#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#include "../../GlobalInclude.h"

//多表查询 数据库表pur-quot和pur-quot-entry
//pur-quot的字段不带前缀
//pur-quot-entry的字段带entry前缀
class PurQuotFindDetailBillVO
{
//pur-quot的字段
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效
	CC_SYNTHESIZE(string, is_effective, Is_effective);
	//已关闭
	CC_SYNTHESIZE(string, is_closed, Is_closed);
	//已作废
	CC_SYNTHESIZE(string, is_voided, Is_voided);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//采购询价单
	//是否临时供应商
	CC_SYNTHESIZE(string, is_temp_supplier, Is_temp_supplier);
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
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//核批结果
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

//----明细(pur-quot-entry的字段)
	//源单分录号
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	//物料
	CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
	//规格型号
	//单位
	CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
	//数量
	CC_SYNTHESIZE(string, entry_qty, Entry_qty);
	//税率
	CC_SYNTHESIZE(string, entry_tax_rate, Entry_tax_rate);
	//含税单价
	CC_SYNTHESIZE(string, entry_price, Entry_price);
	//折扣率
	CC_SYNTHESIZE(string, entry_discount_rate, Entry_discount_rate);
	//含税金额
	CC_SYNTHESIZE(string, entry_amt, Entry_amt);
	//备注
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	//自定义1
	CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
	//自定义2
	CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotFindDetailBillVO,
//pur-quot字段
 bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided,
		subject, is_temp_supplier, supplier_id, supplier_name, payment_method, delivery_time, delivery_place,
		contact, phone, fax, email, remark, approval_remark, attachment, approval_result_type,
//pur-quot-entry字段
entry_src_no, entry_material_id, entry_unit_id, entry_qty, entry_tax_rate, entry_price, entry_discount_rate,
entry_amt, entry_remark, entry_custom1, entry_custom2);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_

