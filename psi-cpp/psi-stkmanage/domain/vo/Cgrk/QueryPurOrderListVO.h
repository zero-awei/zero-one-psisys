#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _QUERY_PUR_ORDER_LIST_VO_
#define _QUERY_PUR_ORDER_LIST_VO_


class QueryPurOrderListVO 
{
	//ID
	CC_SYNTHESIZE(string, id, ID);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//采购类型
	CC_SYNTHESIZE(string, purType, PurType);
	//付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	//预付款余额
	CC_SYNTHESIZE(double, prePaymentBal, PrePaymentBal);
	//结算方式
	CC_SYNTHESIZE(string, settleMethod, SettleMethod);
	//交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliverTime);
	//交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliverPlace);
	//交货方式
	CC_SYNTHESIZE(string, deliveryMethod, DeliverMethod);
	//已入库数量
	CC_SYNTHESIZE(double, inQty, InQty);
	//已入库成本
	CC_SYNTHESIZE(double, inCost, InCost);	
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoiceAmt);
	//发票类型
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//已结算金额
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);

public:

	BIND_TO_JSON(QueryPurOrderListVO, id, billNo, billDate, purType, paymentMethod, prePaymentBal, settleMethod, deliveryTime, deliveryPlace,
		deliveryMethod, inQty, inCost, invoicedAmt, invoiceType, amt, isClosed, opDept, operator1, qty, remark, settleAmt, settledAmt, srcNo, subject, supplierId);
};

#endif // !_QUERY_PUR_ORDER_LIST_QUERY_