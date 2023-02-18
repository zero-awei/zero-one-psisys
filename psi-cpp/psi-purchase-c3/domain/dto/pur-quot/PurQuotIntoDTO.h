#pragma once
#ifndef _PUR_QUOT_INTO_DTO_H_
#define _PUR_QUOT_INTO_DTO_H_
#include "../FileDTO.h"
class PurQuotIntoDTO : public FileDTO {

	//单据编号,已生效, 已关闭,已作废---服务器自动生成, 不可更改
	//单据日期, 是否临时供应商---服务器自动生成, 可以更改

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
		BIND_FROM_TO_NORMAL(j, t, remark);


	}
};

#endif // !
