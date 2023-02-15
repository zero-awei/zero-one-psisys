#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _QueryBillList_DO_
#define _QueryBillList_DO_
#include "../DoInclude.h"

/**
 * 查询单据列表数据库实体类
 */
class QueryBillListDO
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
	QueryBillListDO() {
		id = 0;
		billDateStart = "";
		billDateEnd = "";
		subject = -1;
		supplierId = "";
		billStage = "";
		isEffective =0;
		isClosed = 1;
		isVoided = 1;
	}
};

#endif // !_QueryBillList_DO_
