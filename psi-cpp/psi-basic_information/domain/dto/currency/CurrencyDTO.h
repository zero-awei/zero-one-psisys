#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/14 15:18:04
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
#ifndef _CURRENCY_DTO_
#define _CURRENCY_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * 基础资料币种传输对象
 */
class CurrencyDTO : public FileDTO
{
	// 数据库内编号 Id
	CC_SYNTHESIZE(string, id, Id);
	// 代码 
	CC_SYNTHESIZE(string, code, Code);
	// 名称 
	CC_SYNTHESIZE(string, name, Name);
	// 本币 
	CC_SYNTHESIZE(int, isFunctional, IsFunctional);
	// 启用 
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	// 创建人 
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间 
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人 
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, CurrencyDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, code);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_I(j, t, isFunctional);
		BIND_FROM_TO_I(j, t, isEnabled);
		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		BIND_FROM_TO_NORMAL(j, t, remarks);
	}

	BIND_TO_JSON(CurrencyDTO, id, code, name, isFunctional, isEnabled, createBy, createTime, updateBy, updateTime, remarks);
};

#endif // !_CURRENCY_DTO_
