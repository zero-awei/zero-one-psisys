#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _ENTRY_PUR_INQUIRY_EXPORT_VO_H_
#define _ENTRY_PUR_INQUIRY_EXPORT_VO_H_
#include "../../GlobalInclude.h"

/**
 * 显示对象 —— 采购询价单明细列表，即采购申请单信息
 */


 //采购询价单明细—采购申请单
class EntryPurInquiryExportVO
{
	// 物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	// 单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	// 数量
	CC_SYNTHESIZE(double, entry_qty, Entry_qty);
	// 税率%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	// 参考含税单价
	CC_SYNTHESIZE(double, price, Price);
	// 参考含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 源单分录号
	CC_SYNTHESIZE(string, src_entry_no, Src_entry_no);
	// 分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// 源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	// 源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(EntryPurInquiryExportVO, material_id, unit_id, entry_qty, tax_rate, price, amt, custom1,
				 src_entry_no, entry_no, custom2, src_entry_id, src_bill_type, remark, bill_no,src_bill_id);
};


#endif // !_ENTRY_PUR_INQUIRY_EXPORT_VO_
