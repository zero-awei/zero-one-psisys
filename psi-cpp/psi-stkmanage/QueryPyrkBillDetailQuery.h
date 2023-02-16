#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: 2022/10/25 11:36:29
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


// 查询单据详细信息

#include "../psi-stkmanage/domain/query/PageQuery.h"
//#include "../../psi-stkmanage/domain/do/"

#ifndef _QUERY_PYRK_BILL_Detail_QUERY_
#define _QUERY_PYRK_BILL_Detail_QUERY_

class QueryCgrkBillDetailsQuery {
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据阶段
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);

public:
	// 绑定from_json
	friend void from_json(const json& j, QueryCgrkBillDetailsQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
		//BIND_FROM_TO_NORMAL(j, t, BillStage);
		//BIND_FROM_TO_NORMAL(j, t, BillSDate); //  有问题 待修改
	} 
};

#endif // !_QUERY_PYRK_BILL_Detail_QUERY_