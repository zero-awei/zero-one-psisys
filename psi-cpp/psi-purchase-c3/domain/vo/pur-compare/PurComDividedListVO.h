#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:55:35

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

#ifndef _PUR_COM_DIVIDE_LIST_VO_
#define _PUR_COM_DIVIDE_LIST_VO_

#include "../../GlobalInclude.h"


/**
 * 报价单分录列表显示对象
 */
class PurComDividedListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// # 分录编号
	CC_SYNTHESIZE(string, entryNo, EntryNo);
	// 物料
	CC_SYNTHESIZE(string, materialName, MaterialName);
	// 规格型号
	CC_SYNTHESIZE(string, specifications, Specifications);
	// 单位
	CC_SYNTHESIZE(string, unitName, UnitName);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 税率
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// 含税价格
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// 含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComDividedListVO, billNo, entryNo, materialName, specifications, unitName, qty, taxRate, \
		price, discountRate, amt, remark, custom1, custom2);
	//PurComDividedListVO()
	//{
	//	this->setBillNo("CGBJ100QZP");
	//	this->setSrcEntryId("214");
	//	this->setRemark("测试");
	//}
};

#endif 


