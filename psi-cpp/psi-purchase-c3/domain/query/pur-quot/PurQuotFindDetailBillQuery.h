#pragma once
#ifndef __PUR_QUOT_FIND_DETAIL_QUERY_H_
#define __PUR_QUOT_FIND_DETAIL_QUERY_H_

#include "../PageQuery.h"

class PurQuotFindDetailBillQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//-----------------------不需要下面的内容(阿坤)
	////单据日期--开始, 数据库里面没有这个字段
	//CC_SYNTHESIZE(string, bill_date_begin, Bill_date_begin);
	////单据日期--结束
	//CC_SYNTHESIZE(string, bill_date_end, Bill_date_end);
	//// 单据主题
	//CC_SYNTHESIZE(string, subject, Subject);
	//// 单据阶段
	//CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//// 已生效
	//CC_SYNTHESIZE(string, is_effective, Is_effective);
	//// 已关闭
	//CC_SYNTHESIZE(string, is_closed, Is_closed);
	//// 已作废
	//CC_SYNTHESIZE(string, is_voided, Is_voided);
public:
	friend void from_json(const json& j, PurQuotFindDetailBillQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		//BIND_FROM_TO_NORMAL(j, t, bill_date_begin);
		//BIND_FROM_TO_NORMAL(j, t, bill_date_end);
		//BIND_FROM_TO_NORMAL(j, t, subject);
		//BIND_FROM_TO_NORMAL(j, t, bill_stage);
		//BIND_FROM_TO_NORMAL(j, t, is_effective);
		//BIND_FROM_TO_NORMAL(j, t, is_closed);
		//BIND_FROM_TO_NORMAL(j, t, is_voided);
	}
};
#endif