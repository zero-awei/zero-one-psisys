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
#ifndef _PUR_COM_ENTRY_QUERY_
#define _PUR_COM_ENTRY_QUERY_

#include "../PageQuery.h"

/**
 * 采购比价明细查询对象
 */
class PurComEntryQuery : public PageQuery {
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);

public:
	// 绑定from_json
	friend void from_json(const json& j, PurComEntryQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};
#endif // !_PUR_COM_ENTRY_QUERY_
