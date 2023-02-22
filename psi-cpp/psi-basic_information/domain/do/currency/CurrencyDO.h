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
	// 代码 Code
	CC_SYNTHESIZE(string, code, Code);
	// 名称 name
	CC_SYNTHESIZE(string, name, Name);
	// 本币 isFunctional
	CC_SYNTHESIZE(string, isFunctional, IsFunctional);
	// 启用 isEnabled
	CC_SYNTHESIZE(string, isEnabled, IsEnabled);
	// 创建人 createBy
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间 createTime
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人 updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间 updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	CurrencyDO() {
		code = "1";
		name = "";
		isFunctional = "1";
		isEnabled = "1";
		remarks = "";
		createTime = "";
		createBy = "";
		updateTime = "";
		updateBy = "";
	}
};

#endif // !_CURRENCY_DO_
