#pragma once

#ifndef _PURINQUIRYFINDBILL_DTO_
#define _PURINQUIRYFINDBILL_DTO_

#include "../../GlobalInclude.h"

/**
 * 传输对象 —— 采购询价单查询信息列表
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
	BIND_TO_JSON(PurInquiryFindBillDTO, purInquiryBillNo, purInquiryBillDate, purInquirySubject,
		purInquiryIsEffective, purInquiryIsClosed, purInquiryIsVoided);
};

#endif // !_PURINQUIRYFINDBILL_DTO_