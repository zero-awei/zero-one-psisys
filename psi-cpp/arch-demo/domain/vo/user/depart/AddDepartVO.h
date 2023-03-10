#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:29:25

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
#ifndef _UPDATE_DEPART_VO_
#define _UPDATE_DEPART_VO_

#include "../../../GlobalInclude.h"

/**
 * 示例添加部门显示对象
 */
class AddDepartVO
{
	// 名称
	CC_SYNTHESIZE(string, departName, DepartName);
	// 电话
	CC_SYNTHESIZE(string, phone, Phone);
	// 邮箱
	CC_SYNTHESIZE(string, mail, Mail);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(AddDepartVO, departName, phone, mail);
};

#endif // !_UPDATE_DEPART_DTO_