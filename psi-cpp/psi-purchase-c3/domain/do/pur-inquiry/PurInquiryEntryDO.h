#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/20 15:27

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

#ifndef __PUR_INQUIRY_ENTRY_DO_H__
#define __PUR_INQUIRY_FIND_DETAIL_BILL_DO_H__

#include "../DoInclude.h"

class PurInquiryEntryDO
{
	// ID
	CC_SYNTHESIZE(string, entry_id, Entry_id);
	// 主表
	CC_SYNTHESIZE(string, mid, Mid);
	// 单据号
	CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
	// 分录号
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	// 源单类型
	CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
	// 源单id
	CC_SYNTHESIZE(string, entry_src_bill_id, Entry_src_bill_id);
	// 源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	// 源单分录号
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	// 物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	// 计量单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	// 数量
	CC_SYNTHESIZE(double, entry_qty, Entry_qty);
	// 税率%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	// 参考含税单价
	CC_SYNTHESIZE(double, price, Price);
	// 参考含税金额
	CC_SYNTHESIZE(double, entry_amt, Entry_Amt);
	// 备注
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);


public:
	PurInquiryEntryDO() {
		entry_id = "";
		mid = "";
		entry_bill_no = "";
		entry_no = 1;
		entry_src_bill_type = "";
		entry_src_bill_id = "";
		src_entry_id;
		entry_src_no = "";
		material_id = "";
		unit_id = "";
		entry_qty = -1;
		tax_rate = 0.1;
		price = 1;
		entry_amt = 1;
		entry_remark = "";
		custom1 = "";
		custom2 = "";
	}

};





#endif  //  !__PUR_INQUIRY_FIND_DETAIL_BILL_DO_H__