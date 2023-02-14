#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _Query_Bill_List_DTO_
#define _Query_Bill_List_DTO_
#include "../../GlobalInclude.h"
/**
 * 查询单据列表传输对象
 */
class QueryBillListDTO
{
	// 单据编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据日期-开始
	CC_SYNTHESIZE(string, bill_date_start, Bill_Date_Start);
	// 单据日期-结束
	CC_SYNTHESIZE(string, bill_date_end, Bill_Date_End);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_Id);
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_Stage);
	// 是否生效
	CC_SYNTHESIZE(uint64_t, is_effective, Is_effective);
	// 是否关闭
	CC_SYNTHESIZE(uint64_t, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(uint64_t, is_voided, Is_voided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, QueryBillListDTO& t); // NOLINT
	BIND_TO_JSON(QueryBillListDTO, id, bill_date_start, bill_date_end, subject, supplier_id, bill_stage,is_effective,is_closed,is_voided);
};

#endif // !_SAMPLE_DTO_