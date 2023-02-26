#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2022/21/22 20:30:00

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

#ifndef __PURORDERENTRYDO_H__
#define __PURORDERENTRYDO_H__
#include "../DoInclude.h"

/**
* 采购订单明细表DO领域模型
*/
class PurOrderEntryDO
{
private:
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcBillId
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	//计量单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//税率%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//含税单价
	CC_SYNTHESIZE(double, price, Price);
	//折扣率%
	CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	//税额
	CC_SYNTHESIZE(double, tax, Tax);
	//含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已入库数量
	CC_SYNTHESIZE(double, in_qty, In_qty);
	//已入库成本
	CC_SYNTHESIZE(double, in_cost, In_cost);
	//结算数量
	CC_SYNTHESIZE(double, settle_qty, Settle_qty);
	//结算金额
	CC_SYNTHESIZE(double, settle_amt, Settle_amt);
	//已开票数量
	CC_SYNTHESIZE(double, invoiced_qty, Invoiced_qty);
	//已开票金额
	CC_SYNTHESIZE(double, invoiced_amt, Invoiced_amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);
	
	PurOrderEntryDO() {
		id = "";
		bill_no = "";
		entry_no = "";
		src_bill_type = "";
		src_bill_id = "";
		src_no = "";
		unit_id = "";
		qty = -1;
		amt = -1;
		remark = "";
		custom1 = "";
		custom2 = "";
		mid = "";
		discount_rate = -1;
		tax = -1;
		in_qty = -1;
		in_cost = -1;
		settle_qty = -1;
		settle_amt = -1;
		invoiced_qty = -1;
		invoiced_amt = -1;
	}
};

#endif
