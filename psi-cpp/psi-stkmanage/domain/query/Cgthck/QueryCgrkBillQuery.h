#pragma once
#ifndef _QUERY_CGRK_BILL_QUERY_
#define _QUERY_CGRK_BILL_QUERY_

#include "../PageQuery.h"

/**
* 采购退货出库下的查询采购入库单分录列表对象
*/
class QueryCgrkBillQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据开始日期
	CC_SYNTHESIZE(std::string, billDateStart, BillDateStart);
	// 单据结束日期
	CC_SYNTHESIZE(std::string, billDateEnd, BillDateEnd);
	// 发票类型
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
public:
	// 绑定from_json
	friend void from_json(const json& j, QueryCgrkBillQuery& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, invoiceType);
	}
};
#endif // !_QUERY_CGRK_BILL_QUERY_
