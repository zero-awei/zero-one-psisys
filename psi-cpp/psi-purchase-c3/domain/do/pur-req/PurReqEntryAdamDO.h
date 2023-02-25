#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2023/2/22 9:08

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
#ifndef __PUR_REQ_ENTRY_ADAM_DO_H_
#define __PUR_REQ_ENTRY_ADAM_DO_H_

#include "../../GlobalInclude.h"

//订单明细列表需要的内容
class PurReqEntryAdamDO
{
	//id
	CC_SYNTHESIZE(string, id, Id);
	//主表id
	CC_SYNTHESIZE(string, mid, Mid);
	//单据编号
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
	//含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	//建议供应商
	CC_SYNTHESIZE(string, suggestSupplierId, SuggestSupplierId);
	//已订购数量
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);
public:
	PurReqEntryAdamDO() {
		srcBillType = "";
		srcBillId = "";
		srcEntryId = "";
		srcNo = "";
		taxRate = -1;
		price = 0.000000;
		amt = 0.00;
		suggestSupplierId = "";
		remark = "";
		custom1 = "";
		custom2 = "";
		version = -1;
	}
};

#endif // !__PUR_REQ_ENTRY_ADAM_DO_H_