#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _PURORDERENTRY_DO_
#define _PURORDERENTRY_DO_
#include "../DoInclude.h"

/**
 * stk_io_entry数据库实体类
 */
class PurOrderEntryDO
{
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//单据号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//分录号
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//源单分录号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//计量单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//税率%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//含税单价
	CC_SYNTHESIZE(double, price, Price);
	//折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//税额
	CC_SYNTHESIZE(double, tax, Tax);
	//含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已入库数量
	CC_SYNTHESIZE(double, inQty, InQty);
	//已入库成本
	CC_SYNTHESIZE(double, inCost, InCost);
	//结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//已开票数量
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);



public:

};

#endif // !_PURORDERENTRY_DO_
