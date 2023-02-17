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
#ifndef _QUERY_PUR_ORDER_ENTRY_VO_
#define _QUERY_PUR_ORDER_ENTRY_VO_


class QueryPurOrderEntryVO
{
	//ID
	CC_SYNTHESIZE(string, id, ID);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//分录号
	CC_SYNTHESIZE(int, entryNo, EntryNO);
	//折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//已入库数量
	CC_SYNTHESIZE(double, inQty, InQty);
	//已入库成本
	CC_SYNTHESIZE(double, inCost, InCost);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoiceAmt);
	//已开票数量
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//物料编码
	CC_SYNTHESIZE(string, materialCode, MaterialCode);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//规格型号
	CC_SYNTHESIZE(string, materialModel, MaterialModel);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//含税单价
	CC_SYNTHESIZE(double, price, Price);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryType);
	//源单分录号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 税率
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//计量单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	//版本
	CC_SYNTHESIZE(string, version, Version);


public:
	QueryPurOrderEntryVO()
	{
		id = "7635498";
	}
	BIND_TO_JSON(QueryPurOrderEntryVO, id, billNo, subject, custom1, custom2, entryNo, discountRate, inQty, inCost, invoicedAmt, invoicedQty, materialCode, materialId, materialModel, mid, price, qty, remark,
		settleAmt, settleQty, srcBillId, srcBillType, srcEntryId, srcNo, tax, taxRate, unitId, version);
};

#endif // !_QUERY_PUR_ORDER_ENTRY_VO_