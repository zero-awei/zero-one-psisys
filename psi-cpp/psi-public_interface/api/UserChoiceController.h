#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/13 16:41

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
#ifndef _USERCHOICECONTROLLER_H_
#define _USERCHOICECONTROLLER_H_

#include "../domain/vo/DepartVO.h"
#include "../domain/vo/UserVO.h"
#include "../domain/vo/JsonVO.h"
#include "../domain/vo/PageVO.h"
#include "../domain/query/DepartNameQuery.h"
#include "../domain/query/UserQuery.h"

class UserChoiceController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryDepart, execQueryDepart, DepartNameQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryUser, execQueryUser, UserQuery);
private:
	//查询某区域的下辖区
	JsonVO<PageVO<DepartVO>>execQueryDepart(const DepartNameQuery& query, const PayloadDTO& payload);
	//查询用户
	JsonVO<PageVO<UserVO>>execQueryUser(const UserQuery& query, const PayloadDTO& payload);
};

#endif // _USERCHOICECONTROLLER_H_