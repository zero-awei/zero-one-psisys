#pragma once

#ifndef _PURINQUIRYFINDDETAILBILL_DTO_
#define _PURINQUIRYFINDDETAILBILL_DTO_

#include "../../GlobalInclude.h"


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



#endif  // !_PURINQUIRYFINDDETAILBIL__DTO_