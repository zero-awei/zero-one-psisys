#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/14 17:01

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
#ifndef _SUPPLIER_CATEGORY_QUERY_
#define _SUPPLIER_CATEGORY_QUERY_

#include "../GlobalInclude.h"

class SupplierCategoryQuery
{
	//供应商名字
	CC_SYNTHESIZE(std::string, name, Name);
	//供应商id
	CC_SYNTHESIZE(uint64_t,id,Id);
public:
	// 绑定from_json
	friend void from_json(const json& j, SupplierCategoryQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
	}
};

#endif // !_SUPPLIER_QUERY_
