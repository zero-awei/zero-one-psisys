#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/21 20:29

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
#ifndef _MATERIALQUERYDO_H_
#define _MATERIALQUERYDO_H_

#include "../DoInclude.h"

class MaterialQueryDO
{
	//物料的编码
	CC_SYNTHESIZE(std::string, code, Code);
	//物料的名称
	CC_SYNTHESIZE(std::string, name, Name);
	//物料的分类
	CC_SYNTHESIZE(std::string, type, Type);
	//税控编码
	CC_SYNTHESIZE(std::string, taxCode, TaxCode);
public:
	MaterialQueryDO()
	{
		code = "";
		name = "";
		type = "";
		taxCode = "";
	}
};

#endif // _MATERIALQUERYDO_H_