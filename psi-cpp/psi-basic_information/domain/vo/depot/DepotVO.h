#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Linsky
 @Date: 2023/2/13 20:31:04

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
#ifndef _DEPOT_VO_
#define _DEPOT_VO_

#include "../../GlobalInclude.h"

/**
 * 基础资料仓库模块
 */
class DepotVO
{
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 助记名
	CC_SYNTHESIZE(string, help_name, Help_name);
	// 电话
	CC_SYNTHESIZE(int, phone, Phone);
	// 启用
	// 备注
	// 创建时间
	// 创建人
	// 修改时间
	// 修改人
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DepotVO, name, id, help_name, phone);
};

class DepotDetailVO
{
	// 上级
	// 下级
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 助记名
	CC_SYNTHESIZE(string, help_name, Help_name);
	// 电话
	CC_SYNTHESIZE(int, phone, Phone);
	// 启用
	// 备注
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DepotVO, name, id, help_name, phone);
};

class DepotActionInfoVO
{
	// 创建时间
	// 创建人
	// 修改时间
	// 修改人
public:
	// 绑定JSON转换方法
};

#endif // !_DEPOT_VO_
