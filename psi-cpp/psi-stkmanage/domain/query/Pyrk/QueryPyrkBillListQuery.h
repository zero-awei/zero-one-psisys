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


//	��ѯ�����б�

#ifndef _QUERY_PYRK_BILL_LIST_QUERY_
#define _QUERY_PYRK_BILL_LIST_QUERY_


#include "stdafx.h"
#include "../psi-stkmanage/domain/query/PageQuery.h"

class QueryPyrkBillListQuery {
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// ��from_json
	friend void from_json(const json& j, QueryPyrkBillListQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_QUERY_PYRK_BILL_LIST_QUERY_
