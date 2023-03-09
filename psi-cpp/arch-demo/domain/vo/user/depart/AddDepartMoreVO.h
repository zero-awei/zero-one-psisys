#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:31:34

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
#ifndef _UPDATE_DEPART_MORE_VO_
#define _UPDATE_DEPART_MORE_VO_

#include "AddDepartVO.h"

/**
 * 添加部门示例详情显示对象
 */
class AddDepartMoreVO : public AddDepartVO
{
	// 名称
	CC_SYNTHESIZE(int, id, Id);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(AddDepartMoreVO, departName, phone, mail, id);
};

#endif // !_UPDATE_DEPART_DTO_