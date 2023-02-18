#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: 2022/10/25 11:34:14
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

#include "stdafx.h"
#ifndef _QUERY_PYRK_BILL_DETAIL_VO_
#define _QUERY_PYRK_BILL_DETAIL_VO_


#include "../psi-stkmanage/domain/GlobalInclude.h"

/**
 * 示例显示对象
 */
class QueryPyrkBillDetailVO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	QueryPyrkBillDetailVO() {
		billNo = "CGRK-230203-974";
	}
	// 绑定JSON转换方法
	BIND_TO_JSON(QueryPyrkBillDetailVO, billNo); // 暂时测试  后面数据 需要直接加上
};

#endif // !_QUERY_PYRK_BILL_DETAIL_VO_