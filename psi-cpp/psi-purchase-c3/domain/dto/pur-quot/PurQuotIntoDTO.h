#pragma once
#ifndef _PUR_QUOT_INTO_DTO_H_
#define _PUR_QUOT_INTO_DTO_H_
#include "../FileDTO.h"
class PurQuotIntoDTO : public FileDTO {

	//单据编号
	CC_SYNTHESIZE(string, bill_no, bill_no);
	////单据日期
	//CC_SYNTHESIZE(string, bill_date, bill_date);
	////已生效
	//CC_SYNTHESIZE(int, is_effective, Is_effective);
	////已关闭
	//CC_SYNTHESIZE(int, is_closed, Is_closed);
	////已作废
	//CC_SYNTHESIZE(int, is_voided, Ss_voided);
	////单据主题
	//CC_SYNTHESIZE(string, subject, subject);
	////付款方式
	//CC_SYNTHESIZE(string, payment_method, payment_method);
	////交货地点
	//CC_SYNTHESIZE(string, delivery_place, delivery_place);
	////联系人
	//CC_SYNTHESIZE(string, contact,contact);
	////联系电话
	//CC_SYNTHESIZE(string, phone, phone);
	////传真
	//CC_SYNTHESIZE(string, fax, fax);
	////电子邮件
	//CC_SYNTHESIZE(string, email, email);
	////备注
	//CC_SYNTHESIZE(string, remark, remark);
	////附件
	//CC_SYNTHESIZE(string, attachment, attachment);
public:
	friend void from_json(const json& j, PurQuotIntoDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		//BIND_FROM_TO_ULL(j, t, bill_date);
		//BIND_FROM_TO_I(j, t, is_effective);
		//BIND_FROM_TO_I(j, t, is_closed);
		//BIND_FROM_TO_I(j, t, is_voided);
		//BIND_FROM_TO_ULL(j, t, payment_method);
		//BIND_FROM_TO_ULL(j, t, delivery_place);
		//BIND_FROM_TO_ULL(j, t, contact);
		//BIND_FROM_TO_ULL(j, t, fax);
		//BIND_FROM_TO_ULL(j, t, email);
		//BIND_FROM_TO_ULL(j, t, remark);
		//BIND_FROM_TO_ULL(j, t, attachment);
	}
};

#endif // !




