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
#ifndef _PUR_REQ_QUERY_
#define _PUR_REQ_QUERY_
#include "../PageQuery.h"

/**
 * 采购请求分页查询对象
 */
class PurReqQuery : public PageQuery{
	// ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 单据阶段		
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		// ID
		BIND_FROM_TO_ULL(j, t, id);
		// 单据编号
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		// 单据日期
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		// 单据主题
		BIND_FROM_TO_NORMAL(j, t, subject);
		// 单据阶段		
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		// 是否生效
		BIND_FROM_TO_I(j, t, is_effective);
		// 是否关闭
		BIND_FROM_TO_I(j, t, is_closed);
		// 是否作废
		BIND_FROM_TO_I(j, t, is_voided);
	}
};
#endif // !_PUR_REQ_QUERY_