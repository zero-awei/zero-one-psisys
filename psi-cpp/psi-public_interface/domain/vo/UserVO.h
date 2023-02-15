#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/13 15:18

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
#include "../GlobalInclude.h"

//选择用户数据
class UserVO
{
	//用户id
	CC_SYNTHESIZE(uint64_t, id, Id);
	//用户账号姓名
	CC_SYNTHESIZE(std::string, username,UserName);
	//用户真实姓名
	CC_SYNTHESIZE(std::string, realname, RealName);
	//用户性别
	CC_SYNTHESIZE(std::string, sex, Sex);
	//用户所属部门
	CC_SYNTHESIZE(std::string, department, Department);
public:
	BIND_TO_JSON(UserVO, id, username,realname,sex,department);
	UserVO()
	{
		id = 1;
		username = "awei";
		realname = "awei";
		sex = "man";
		department = "naowubu";
	}
};

#endif // _USERVO_H_