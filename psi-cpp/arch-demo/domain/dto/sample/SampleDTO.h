#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class SampleDTO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, SampleDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_I(j, t, age);
		BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_SAMPLE_DTO_