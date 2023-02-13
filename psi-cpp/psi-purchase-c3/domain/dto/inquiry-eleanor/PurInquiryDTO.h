#pragma once

#ifndef _PURINQUIRY_DTO_
#define _PURINQUIRY_DTO_

#include "../../GlobalInclude.h"

/**
 * 传输对象 —— 采购询价单列表、指定询价单详细信息
 */

//采购询价单列表
class PurInquiryFindBillDTO
{
//传输对象参数 - 基本信息string
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);
	//单据主题
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
//单据状态
	//是否生效int
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurInquiryFindBillDTO& t); // NOLINT
};


//指定询价单详细信息
class PurInquiryFindDetailBillDTO
{
//基本信息
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);   // 对应mysql数据库中bill_no字段

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurInquiryFindDetailBillDTO& t); // NOLINT
};


//指定询价单的明细分录
class EntryPurInquiry
{
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // 对应mysql数据库中bill_no字段

public:
	// 绑定from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	}
};


#endif // !_PURINQUIRY_DTO_