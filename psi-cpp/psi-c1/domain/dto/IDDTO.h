#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:38:37

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
#ifndef _IDDTO_H_
#define _IDDTO_H_

#include "../GlobalInclude.h"

/**
 * 整形类型编号对象
 */
class IntID
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, IntID& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, id);
	}
};

/**
 * 整形类型编号对象集合
 */
class IntIDs
{
	// 编号
	CC_SYNTHESIZE(std::list<uint64_t>, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, IntIDs& t) { // NOLINT
		BIND_FROM_TO_OBJ(j, t, id, std::list<uint64_t>);
	}
};

/**
 * 字符串类型编号对象
 */
class StringID
{
	// 编号
	CC_SYNTHESIZE(std::string, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, StringID& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

/**
 * 字符串类型编号对象集合
 */
class StringIDs
{
	// 编号
	CC_SYNTHESIZE(std::list<std::string>, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, StringIDs& t) { // NOLINT
		BIND_FROM_TO_OBJ(j, t, id, std::list<std::string>);
	}
};

#endif // !_IDDTO_H_
