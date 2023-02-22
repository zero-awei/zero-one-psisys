#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/21 21:46:32
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
#ifndef _CURRENCY_DO_
#define _CURRENCY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CurrencyDO
{
	// 名称 name
	CC_SYNTHESIZE(string, name, Name);
	// 代码 code
	CC_SYNTHESIZE(string, id, Id);
	// 本币 is_functional
	CC_SYNTHESIZE(string, localCurrency, LocalCurrency);
	// 启用 is_enabled
	CC_SYNTHESIZE(string, start, Start);
	// 创建人 create_by
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// 创建时间 create_time
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// 修改人 update_by
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
	// 修改时间 update_time
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	CurrencyDO() {
		id = "1";
		name = "";
		localCurrency = "1";
		start = "1";
		remarks = "";
		creationTime = "";
		creationPeo = "";
		modiTime = "";
		modiPeo = "";
	}
};

#endif // !_CURRENCY_DO_
