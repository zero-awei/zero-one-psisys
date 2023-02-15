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
#ifndef _QUERYBILLLIST_VO_
#define _QUERYBILLLIST_VO_

#include "../../GlobalInclude.h"

/**
 * 查询单据列表显示对象
 */
class QueryBillListVO
{
	// 单据编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据日期-开始
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	// 单据日期-结束
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 是否生效
	CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	// 是否关闭
	CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, QueryBillListVO& t); // NOLINT
	BIND_TO_JSON(QueryBillListVO, id, billDateStart, billDateEnd, subject,supplierId, billStage, isEffective, isClosed, isVoided);

};

#endif // !_QueryBillList_VO_