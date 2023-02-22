#pragma once
#ifndef _QUERY_CGRK_BILL_LISTS_VO_
#define _QUERY_CGRK_BILL_LISTS_VO_

#include "../../GlobalInclude.h"
class QueryCgrkBillListsVO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 入库类型
	CC_SYNTHESIZE(std::string, stockIoType, StockIoType);
	// 源单号
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 业务部门
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// 业务员
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// 结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// 已结算金额
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// 已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	// 发票类型
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// 有涨吨
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// 已关闭
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
public:
	BIND_TO_JSON
	(
		QueryCgrkBillListsVO, billNo, billDate, subject, stockIoType, srcNo, supplierId, 
		opDept, srcOperator, settleAmt, settledAmt, invoicedAmt, invoiceType, hasSwell, isClosed
	);
};

#endif // !_QUERY_CGRK_BILL_LISTS_VO_
