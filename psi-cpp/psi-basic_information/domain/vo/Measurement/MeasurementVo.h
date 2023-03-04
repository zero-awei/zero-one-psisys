#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _MEASUREMNET_VO_
#define _MEASUREMENT_VO_

#include "../../GlobalInclude.h"
#include <string>

/**
 * 显示对象
 */
class MeasurementVO
{
	//主键ID
	CC_SYNTHESIZE(string, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 符号
	CC_SYNTHESIZE(string, symbol, Symbol);
	// 换算系数
	CC_SYNTHESIZE(double, factor, Factor);
	// 启用
	CC_SYNTHESIZE(string, is_enabled, Is_enabled);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(MeasurementVO, id, name, symbol, factor, is_enabled, create_time, create_by, update_time, update_by);
};

#endif // !_MEASUREMENT_VO_
