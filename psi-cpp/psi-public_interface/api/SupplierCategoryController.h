#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/14 18:50

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
#ifndef SUPPLIER_CATEGORY_CONTROLLER_
#define SUPPLIER_CATEGORY_CONTROLLER_
#include"../domain/query/SupplierCategoryQuery.h"
#include"../domain/vo/SupplierCategoruVO.h"
#include "../domain/vo/JsonVO.h"

class SupplierCategoryController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(querySupplierCategory, execQuerySupplierCategory, SupplierCategoryQuery);
private:
	JsonVO<list<SuppliersCategoryVO>>execQuerySupplierCategory(const SupplierCategoryQuery& query,const PayloadDTO& payload);
};

#endif // !SUPPLIER_CATEGORY_CONTROLLER_
