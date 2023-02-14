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
#ifndef _Measurement_DTO_
#define _Measurement_DTO_

#include "../../GlobalInclude.h"

/**
 * 传输对象
 */
class MeasurementDTO
{
	// 名称
	CC_SYNTHESIZE(string, 名称, 名称);
	// 符号
	CC_SYNTHESIZE(string, 符号, 符号);
	// 换算系数
	CC_SYNTHESIZE(uint64_t, 换算系数, 换算系数);
	// 启用
	CC_SYNTHESIZE(string, 启用, 启用);
	// 创建时间
	CC_SYNTHESIZE(string, 创建时间, 创建时间);
	// 创建人
	CC_SYNTHESIZE(string, 创建人, 创建人);
	// 修改时间
	CC_SYNTHESIZE(string, 修改时间, 修改时间);
	// 修改人
	CC_SYNTHESIZE(string, 修改人, 修改人);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, MeasurementDTO& t); // NOLINT
	BIND_TO_JSON(MeasurementDTO, 名称, 符号, 换算系数, 启用, 创建时间, 创建人, 修改时间, 修改人);
};

#endif // !_Measurement_DTO_
