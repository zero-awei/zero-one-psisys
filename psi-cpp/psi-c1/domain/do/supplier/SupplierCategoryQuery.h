#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/23 20:39

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
#ifndef _SUPPLIERCATEGORYQUERY_H_
#define _SUPPLIERCATEGORYQUERY_H_

#include "../DoInclude.h"

class SupplierCategoryQueryDO
{
	//??Ӧ??????
	CC_SYNTHESIZE(std::string, name, Name);
public:
	SupplierCategoryQueryDO()
	{
		name = "";
	}
};
#endif // _SUPPLIERCATEGORYQUERY_H_