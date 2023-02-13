#pragma once

#ifndef _PURINQUIRY_QUERY_
#define _PURINQUIRY_QUERY_

#include "../PageQuery.h"

/**
 * 示例分页查询对象
 */
class PurInquiryFindBillQuery : public PageQuery
{
//查询的对象信息
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);
	//单据主题
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
//单据状态
	//是否生效
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);


public:
	// 绑定from_json
	friend void from_json(const json& j, PurInquiryFindBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
		BIND_FROM_TO_ULL(j, t, purInquiryBillDate);
		BIND_FROM_TO_ULL(j, t, purInquirySubject);
		BIND_FROM_TO_I(j, t, purInquiryIsEffective);
		BIND_FROM_TO_I(j, t, purInquiryIsClosed);
		BIND_FROM_TO_I(j, t, purInquiryIsVoided);
	}
};



//指定询价单详细信息
class PurInquiryFindDetailBillQuery : public PageQuery
{
//查询的指定对象信息
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // 对应mysql数据库中bill_no字段

public:
	// 绑定from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	}
};

#endif // !_PURINQUIRY_QUERY_