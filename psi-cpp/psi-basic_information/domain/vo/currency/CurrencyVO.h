#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/14 15:40:13
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
#ifndef _Currency_VO_
#define _Currency_VO_

#include "../../GlobalInclude.h"

/**
 * 基础资料币种模块
 */
class CurrencyVO
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
	BIND_TO_JSON(CurrencyVO, id, code, name, isFunctional, isEnabled, createBy, createTime, updateBy, updateTime, remarks);
};
#endif // !_Currency_VO_
