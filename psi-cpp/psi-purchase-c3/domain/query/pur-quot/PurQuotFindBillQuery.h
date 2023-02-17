#pragma once
#ifndef __PUR_QUOT_FIND_BILL_QUERY_H_
#define __PUR_QUOT_FIND_BILL_QUERY_H_

#include "../PageQuery.h"

class PurQuotFindBillQuery : public PageQuery
{

	// 单据编号
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
	// 单据日期 开始
	CC_SYNTHESIZE(string, receiptTimeBegin, ReceiptTimeBegin);
	// 单据日期 结束
	CC_SYNTHESIZE(string, receiptTimeEnd, ReceiptTimeEnd);
	// 单据主题
	CC_SYNTHESIZE(string, receiptTheme, ReceiptTheme);
	// 单据阶段
	CC_SYNTHESIZE(string, receiptStage, ReceiptStage);
	// 已生效
	CC_SYNTHESIZE(string, isWork, IsWork);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isAbolish, IsAbolish);
public:
	friend void from_json(const json& j, PurQuotFindBillQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, receiptId);
		BIND_FROM_TO_NORMAL(j, t, receiptTimeBegin);
		BIND_FROM_TO_NORMAL(j, t, receiptTimeEnd);
		BIND_FROM_TO_NORMAL(j, t, receiptTheme);
		BIND_FROM_TO_NORMAL(j, t, receiptStage);
		BIND_FROM_TO_NORMAL(j, t, isWork);
		BIND_FROM_TO_NORMAL(j, t, isClose);
		BIND_FROM_TO_NORMAL(j, t, isAbolish);
	}
};

#endif
