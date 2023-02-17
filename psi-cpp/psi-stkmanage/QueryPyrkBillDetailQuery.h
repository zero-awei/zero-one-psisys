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


// ��ѯ������ϸ��Ϣ
#include "stdafx.h"
#include "../psi-stkmanage/domain/query/PageQuery.h"
//#include "../../psi-stkmanage/domain/do/"

#ifndef _QUERY_PYRK_BILL_DETAIL_QUERY_
#define _QUERY_PYRK_BILL_DETAIL_QUERY_

class QueryCgrkBillDetailsQuery {
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billtage, BillStage);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);

public:
	// ��from_json
	friend void from_json(const json& j, QueryCgrkBillDetailsQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billtage);
		BIND_FROM_TO_NORMAL(j, t, billDate); 
	} 
};

#endif // !_QUERY_PYRK_BILL_DETAIL_QUERY_