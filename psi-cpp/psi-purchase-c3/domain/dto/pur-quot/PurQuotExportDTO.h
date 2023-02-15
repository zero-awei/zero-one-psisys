#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 09:55:01

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
#ifndef _PUR_QUOT_EXPORT_DTO_
#define _PUR_QUOT_EXPORT_DTO_

#include "../PageQuery.h"

/*
查询单据列表显示对象
*/

class PurQuotExportDTO: public PageQuery {
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭			
	CC_SYNTHESIZE(int, isClose, IsClose);
	//已作废			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurQuotExportDTO& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_ULL(j, t, billNo);
		BIND_FROM_TO_ULL(j, t, billDate);
		BIND_FROM_TO_ULL(j, t, subject);
		BIND_FROM_TO_ULL(j, t, billStage);
		BIND_FROM_TO_i(j, t, isEffective);
		BIND_FROM_TO_i(j, t, isClose);
		BIND_FROM_TO_i(j, t, isVoided);
	}
};
#endif // !




