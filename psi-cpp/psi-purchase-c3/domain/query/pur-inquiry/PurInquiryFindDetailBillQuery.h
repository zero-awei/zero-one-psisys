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
#ifndef _PUR_INQUIRY_FIND_DETAIL_BILL_QUERY_H_
#define _PUR_INQUIRY_FIND_DETAIL_BILL_QUERY_H_

#include "../PageQuery.h"

/**
 * 示例查询对象 —— 指定采购询价单详情（根据单据编号查询）
 */

class PurInquiryFindDetailBillQuery : public PageQuery
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);    // 对应mysql数据库中bill_no字段

public:
	// 绑定from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { 
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};

#endif // !_PUR_INQUIRY_FIND_DETAIL_BILL_QUERY_