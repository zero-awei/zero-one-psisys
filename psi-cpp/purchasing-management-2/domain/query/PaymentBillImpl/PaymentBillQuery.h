#pragma once

#ifndef _PAYMENT_BILL_Query_
#define _PAYMENT_BILL_Query_

#include "../PageQuery.h"


//查询单据列表
class PaymentBillQuery : public PageQuery {
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id)
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭			
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PaymentBillQuery& pbq) {
		BIND_FROM_TO_ULL(j, pbq, bill_no);
		BIND_FROM_TO_ULL(j, pbq, bill_date);
		BIND_FROM_TO_ULL(j, pbq, subject);
		BIND_FROM_TO_ULL(j, pbq, supplier_id);
		BIND_FROM_TO_ULL(j, pbq, bill_stage);
		BIND_FROM_TO_I(j, pbq, is_effective);
		BIND_FROM_TO_I(j, pbq, is_closed);
		BIND_FROM_TO_I(j, pbq, is_voided);
	}
};


/*
查询指定单据详细信息
*/
class PaymentBillDetailQuery {
	//指定的单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PaymentBillDetailQuery& pbdq) {
		BIND_FROM_TO_ULL(j, pbdq, bill_no);
	}
};


#endif
