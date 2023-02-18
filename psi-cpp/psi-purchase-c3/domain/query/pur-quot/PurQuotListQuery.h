#pragma once
#ifndef __PUR_QUOT_LIST_QUERY_H_
#define __PUR_QUOT_LIST_QUERY_H_

#include "../PageQuery.h"

class PurQuotListQuery : public PageQuery
{

	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//// 单据日期 
	//CC_SYNTHESIZE(string, receiptTime, ReceiptTime);
	//// 单据主题
	//CC_SYNTHESIZE(string, receiptTheme, ReceiptTheme);
	//// 联系人
	//CC_SYNTHESIZE(string, contact, Contact);
	//// 交货日期
	//CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	//// 交货地点
	//CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	//// 已关闭
	//CC_SYNTHESIZE(string, isClose, IsClose);
public:
	friend void from_json(const json& j, PurQuotListQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		//BIND_FROM_TO_NORMAL(j, t, receiptId);
		//BIND_FROM_TO_NORMAL(j, t, receiptTime);
		//BIND_FROM_TO_NORMAL(j, t, receiptTheme);
		//BIND_FROM_TO_NORMAL(j, t, contact);
		//BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		//BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
		//BIND_FROM_TO_NORMAL(j, t, isClose);
	}
};
#endif
