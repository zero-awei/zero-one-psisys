#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:19:03

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
#ifndef _PUR_RER_FIND_Detail_BILL_VO_
#define _PUR_RER_FIND_Detail_BILL_VO_

#include "../../GlobalInclude.h"
#include "PurReqFindBillVO.h"
/*
查询单据列表显示对象
*/
//备注:类的宏里面的字段类型需要更改
class PurReqFindDetailBillVO : public PurReqFindBillVO {
	//源单分录号
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	//规则型号--未找到
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//数量
	CC_SYNTHESIZE(string, qty, Qty);
	//已订数量
	CC_SYNTHESIZE(string, ordered_qty, Ordered_qty);
	//税率
	CC_SYNTHESIZE(string, tax_rate, Tax_rate);
	//参考含税单价
	CC_SYNTHESIZE(string, price, Price);
	//参考含税金额
	CC_SYNTHESIZE(string, amt, Amt);
	//建议供应商
	CC_SYNTHESIZE(string, suggest_supplier_id, Suggest_supplier_id);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurReqFindDetailBillVO, entry_no, material_id, entry_no, unit_id, qty, ordered_qty, tax_rate, price, amt, suggest_supplier_id, remark, custom1, custom2);
};
#endif // !







