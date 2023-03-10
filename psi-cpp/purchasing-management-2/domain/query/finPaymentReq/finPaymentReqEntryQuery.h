#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Papillon
 @Date: 2023/02/16 22:00:00
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
#ifndef _FIN_PAYMENT_REQ_ENTRY_QUERY_
#define _FIN_PAYMENT_REQ_ENTRY_QUERY_


#include "../PageQuery.h"
/*
查询单据列表
*/
class FinPaymentReqEntryQuery {

	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, FinPaymentReqEntryQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif //_FIN_PAYMENT_REQ_ENTRY_QUERY_