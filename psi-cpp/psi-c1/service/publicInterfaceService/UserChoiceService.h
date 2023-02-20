#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/20 20:13

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

#ifndef _USERCHOICESERVICE_H_
#define _USERCHOICESERVICE_H_

#include "../../domain/vo/publicInterfaceVO/UserVO.h"
#include "../../domain/query/publicInterfaceQuery/UserQuery.h"
#include "../../domain/vo/PageVO.h"

class UserChoiceService
{
public:
	// 分页查询所有数据
	PageVO<UserVO> listAll(const UserQuery& query);
};

#endif // _USERCHOICESERVICE_H_