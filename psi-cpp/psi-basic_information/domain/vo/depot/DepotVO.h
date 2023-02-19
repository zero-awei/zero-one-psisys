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
	// 唯一值：id
	CC_SYNTHESIZE(string, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 助记名
	CC_SYNTHESIZE(string, auxName, AuxName);
	// 电话
	CC_SYNTHESIZE(int, phone, Phone);
	// 启用
	CC_SYNTHESIZE(string, start, Start);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
	// 创建时间
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// 创建人
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// 修改时间
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// 修改人
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DepotVO, id, name, code, auxName, phone,start,remarks,creationTime, creationPeo, modiTime, modiPeo);
};

class DepotDetailVO
{
	// 上级
	CC_SYNTHESIZE(string, pid, Pid);
	// 下级
	CC_SYNTHESIZE(string, next, Next);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 助记名
	CC_SYNTHESIZE(string, auxName, AuxName);
	// 电话
	CC_SYNTHESIZE(int, phone, Phone);
	// 启用
	CC_SYNTHESIZE(string, start, Start);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DepotDetailVO, pid, next, name, auxName, phone, start, remarks);
};

class DepotActionInfoVO
{
	// 创建时间
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// 创建人
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// 修改时间
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// 修改人
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(DepotActionInfoVO, creationTime, creationPeo, modiTime, modiPeo);
};

#endif // !_DEPOT_VO_
