#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _USERVO_H_
#define _USERVO_H_

#include "../../GlobalInclude.h"

/**
 * 定义一个修改用户信息结果显示对象
 */
class UserVO
{
	// 昵称
	CC_SYNTHESIZE(std::string, nickname, Nickname);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 身份证号
	CC_SYNTHESIZE(std::string, idCard, IdCard);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(UserVO, nickname, age, idCard);
};

#endif // _USERVO_H_