#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/02/19 23:14:13

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
#ifndef _ADD_PUR_INQUIRY_ENTRYDTO_H_
#define _ADD_PUR_INQUIRY_ENTRYDTO_H_
#include "../../GlobalInclude.h"


class AddPurInquiryEntryDTO
{
	//应该是主表的单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//主表
	CC_SYNTHESIZE(std::string, mid, Mid);
	//ID
	CC_SYNTHESIZE(std::string, id, Id);
	//源单类型
	CC_SYNTHESIZE(std::string, src_bill_type, Src_bill_type);
	//源单分录号
	CC_SYNTHESIZE(std::string, src_no, Src_no);
	//物料
	CC_SYNTHESIZE(std::string, material_id, Material_id);
	//规格型号
	//CC_SYNTHESIZE(std::string, model, Model);
	//单位
	CC_SYNTHESIZE(std::string, unit_id, Unit_id);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//税率
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//参考含税单价
	CC_SYNTHESIZE(double, price, Price);
	//参考含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	//备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);

public:
	friend void from_json(const json& j, AddPurInquiryEntryDTO& t)
	{
		BIND_FROM_TO_I(j, t, entry_no);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, mid);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, material_id);
		BIND_FROM_TO_NORMAL(j, t, unit_id);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, tax_rate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}

};

#endif // !_ADD_PUR_INQUIRY_ENTRYDTO_H_