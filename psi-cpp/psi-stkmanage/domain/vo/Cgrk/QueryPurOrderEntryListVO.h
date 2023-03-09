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
#ifndef _QUERY_PUR_ORDER_ENTRY_LIST_VO_
#define _QUERY_PUR_ORDER_ENTRY_LIST_VO_

#include "../../GlobalInclude.h"
#include "QueryPurOrderEntryVO.h"

class QueryPurOrderEntryListVO
{
	//Ã÷Ï¸ÁÐ±í
	CC_SYNTHESIZE(list<QueryPurOrderEntryVO>, entryList, EntryList);
	


public:
	QueryPurOrderEntryListVO()
	{
		entryList.push_back(QueryPurOrderEntryVO());
		entryList.push_back(QueryPurOrderEntryVO());
	}

};

#endif // !_QUERY_PUR_ORDER_ENTRY_LIST_VO_