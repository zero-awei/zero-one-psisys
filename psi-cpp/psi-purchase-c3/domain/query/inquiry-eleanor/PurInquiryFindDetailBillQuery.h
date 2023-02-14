#pragma once

#ifndef _PURINQUIRYFINDDETAILBILL_QUERY_
#define _PURINQUIRYFINDDETAILBILL_QUERY_

#include "../PageQuery.h"

/**
 * 示例查询对象 —— 指定采购询价单详情（根据单据编号查询）
 */

class PurInquiryFindDetailBillQuery : public PageQuery
{
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // 对应mysql数据库中bill_no字段

public:
	// 绑定from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	}
};

#endif // !_PURINQUIRYFINDDETAILBILL_QUERY_