#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/11 14:00

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

#ifndef _AREAVO_H_
#define _AREAVO_H_
#include "../GlobalInclude.h"

/*
查询后返回的下辖区
*/
class AreaVO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
public:
	//绑定json转换方法
	BIND_TO_JSON(AreaVO, name, id);

};

#endif // _AREAVO_H_