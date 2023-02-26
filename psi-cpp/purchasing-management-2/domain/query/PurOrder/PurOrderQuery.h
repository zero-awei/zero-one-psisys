#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/15 10:55:01

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
#ifndef _PUR_ORDER_QUERY_
#define _PUR_ORDER_QUERY_

#include "../PageQuery.h"

/**
 * 采购订单分页查询对象
 */
class PurOrderQuery : public PageQuery {
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// 业务员
	CC_SYNTHESIZE(string, op_er, Op_er);
	// 单据阶段		
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废.
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurOrderQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		// 单据编号
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		// 单据日期
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		// 单据主题
		BIND_FROM_TO_NORMAL(j, t, subject);
		// 供应商
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		// 业务员
		BIND_FROM_TO_NORMAL(j, t, op_er);
		// 单据阶段		
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		// 是否生效
		BIND_FROM_TO_I(j, t, is_effective);
		// 是否关闭
		BIND_FROM_TO_I(j, t, is_closed);
		// 是否作废
		BIND_FROM_TO_I(j, t, is_voided);
	}
	PurOrderQuery() {
		is_effective= -1;
		is_closed = -1;
		is_voided = -1;
	}
};
#endif // !_PUR_ORDER_QUERY_




