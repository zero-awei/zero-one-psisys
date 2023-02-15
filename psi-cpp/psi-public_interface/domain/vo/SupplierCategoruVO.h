#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/14 18:41

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
#ifndef _SUPPLIERS_CATEGORY_VO_
#define _SUPPLIERS_CATEGORY_VO_
#include"../GlobalInclude.h"

class SuppliersCategoryVO
{
	//供应商类型名字
	CC_SYNTHESIZE(std::string, name, Name);
	//供应商类型对应id
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	SuppliersCategoryVO()
	{
		name = "windows";
		id = 0;
	}
	//绑定json转换方法
	BIND_TO_JSON(SuppliersCategoryVO, name, id);
};
#endif//!_SUPPLIERS_VO_