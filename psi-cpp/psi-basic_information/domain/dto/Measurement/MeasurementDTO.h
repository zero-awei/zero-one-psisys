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
#include "../FileDTO.h"

/**
 * 传输对象
 */
class MeasurementDTO : public FileDTO
{
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 符号
	CC_SYNTHESIZE(string, sign, Sign);
	// 换算系数
	CC_SYNTHESIZE(uint64_t, scale, Scale);
	// 启用
	CC_SYNTHESIZE(string, enable, Enable);
	// 创建时间
	CC_SYNTHESIZE(string, ctime, Ctime);
	// 创建人
	CC_SYNTHESIZE(string, creater, Creater);
	// 修改时间
	CC_SYNTHESIZE(string, rtime, Rtime);
	// 修改人
	CC_SYNTHESIZE(string, riviser, Riviser);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, MeasurementDTO& t); // NOLINT
	BIND_TO_JSON(MeasurementDTO, name, sign, scale, enable, ctime, creater, rtime, riviser);
};

#endif // !_Measurement_DTO_
