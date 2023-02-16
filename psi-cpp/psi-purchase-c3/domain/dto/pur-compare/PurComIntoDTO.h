#pragma once

#ifndef _PUR_COM_INTO_DTO_
#define _PUR_COM_INTO_DTO_

#include "../FileDTO.h"

class PurComIntoDTO :public FileDTO {
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	////单据日期
	//CC_SYNTHESIZE(string, bill_date, Bill_date);
	////已生效
	//CC_SYNTHESIZE(int, is_effective, Is_effective);
	////已关闭
	//CC_SYNTHESIZE(int, is_closed, Is_closed);
	////已作废
	//CC_SYNTHESIZE(int, is_voided, Ss_voided);
	////单据主题
	//CC_SYNTHESIZE(string, subject, Subject);
	////采购询价单编号
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////付款方式
	//CC_SYNTHESIZE(string, payment_method, Payment_method);
	////交货日期
	//CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	////需求地点
	//CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////备注
	//CC_SYNTHESIZE(string, remark, Remark);
	////附件
	//CC_SYNTHESIZE(string, attachment, Attachment);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComIntoDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, bill_no);
		//BIND_FROM_TO_ULL(j, t, bill_date);
		//BIND_FROM_TO_ULL(j, t, is_effective);
		//BIND_FROM_TO_I(j, t, is_closed);
		//BIND_FROM_TO_I(j, t, is_voided);
		//BIND_FROM_TO_I(j, t, subject);
		//BIND_FROM_TO_ULL(j, t, bill_no);
		//BIND_FROM_TO_ULL(j, t, payment_method);
		//BIND_FROM_TO_ULL(j, t, delivery_time);
		//BIND_FROM_TO_ULL(j, t, delivery_place);
		//BIND_FROM_TO_ULL(j, t, remark);
		//BIND_FROM_TO_ULL(j, t, attachment);
	}
};

#endif // !




