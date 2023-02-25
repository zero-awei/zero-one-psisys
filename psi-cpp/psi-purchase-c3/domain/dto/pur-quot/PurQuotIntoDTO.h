#pragma once
#ifndef _PUR_QUOT_INTO_DTO_H_
#define _PUR_QUOT_INTO_DTO_H_
#include "../FileDTO.h"

class PurQuotIntoDTO : public FileDTO {

	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject)
	//采购询价单编号--pur-inquiry里面的字段
	CC_SYNTHESIZE(string, pur_inquiry_bill_no, Pur_inquiry_bill_no)
	//是否临时供应商
	CC_SYNTHESIZE(string, is_temp_supplier, Is_temp_supplier);
	//供应商/临时供应商名
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
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
//-----------------明细开始
//源单分录号
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	//物料
	CC_SYNTHESIZE(string, entry_material_id,Entry_material_id);
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
	friend void from_json(const json& j, PurQuotIntoDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, pur_inquiry_bill_no);
		BIND_FROM_TO_NORMAL(j, t, is_temp_supplier);
		BIND_FROM_TO_NORMAL(j, t, supplier_name);
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		BIND_FROM_TO_NORMAL(j, t, delivery_time);
		BIND_FROM_TO_NORMAL(j, t, delivery_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, entry_src_no);
		BIND_FROM_TO_NORMAL(j, t, entry_material_id);
		BIND_FROM_TO_NORMAL(j, t, entry_unit_id);
		BIND_FROM_TO_NORMAL(j, t, entry_qty);
		BIND_FROM_TO_NORMAL(j, t, entry_tax_rate);
		BIND_FROM_TO_NORMAL(j, t, entry_price);
		BIND_FROM_TO_NORMAL(j, t, entry_discount_rate);
		BIND_FROM_TO_NORMAL(j, t, entry_amt);
		BIND_FROM_TO_NORMAL(j, t, entry_remark);
		BIND_FROM_TO_NORMAL(j, t, entry_custom1);
		BIND_FROM_TO_NORMAL(j, t, entry_custom2);
	}
};

#endif // !
