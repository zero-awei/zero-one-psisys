#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\25 14:33:32

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
#ifndef _PUR_COM_DETAIL_DTO_H_
#define _PUR_COM_DETAIL_DTO_H_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class PurComDetailDTO
{
	// 单据id
	CC_SYNTHESIZE(string, id, Id);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);

	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcbillid
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(string, src_no, Src_no);

	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//物料
	CC_SYNTHESIZE(string, material_id, Material_id);			//数据库必传值
	//计量单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);					//数据库必传值
	//数量
	CC_SYNTHESIZE(double, qty, Qty);							//数据库必传值
	//税率%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);					//数据库必传值

	//含税单价
	CC_SYNTHESIZE(double, price, Price);						//数据库必传值
	//折扣率%
	CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	//含税金额
	CC_SYNTHESIZE(double, amt, Amt);							//数据库必传值
	//排名
	CC_SYNTHESIZE(int, ranking, Ranking);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);

	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComDetailDTO& t)
	{
		//BIND_FROM_TO_NORMAL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, mid);
		BIND_FROM_TO_NORMAL(j, t, bill_no);

		BIND_FROM_TO_I(j, t, entry_no);

		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		BIND_FROM_TO_NORMAL(j, t, src_entry_id);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, material_id);
		BIND_FROM_TO_NORMAL(j, t, unit_id);

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, tax_rate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, discount_rate);
		BIND_FROM_TO_D(j, t, amt);

		BIND_FROM_TO_I(j, t, ranking);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);

		BIND_FROM_TO_I(j, t, version);
	}
};

#endif // !_PUR_COM_DETAIL_DTO_H_