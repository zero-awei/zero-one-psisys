#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/14 16:29

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

#ifndef _DEPART_CHOICE_CONTROLLER_
#define _DEPART_CHOICE_CONTROLLER_

#include "../domain/vo/DepartVO.h"
#include "../domain/vo/JsonVO.h"
#include "../domain/query/DepartNameQuery.h"

class DepartChoiceController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryDepart, execQueryDepart, DepartNameQuery);
private:
	JsonVO<list<DepartVO>>execQueryDepart(const DepartNameQuery& query, const PayloadDTO& payload);
};

#endif //!_DEPART_CHOICE_CONTROLLER_