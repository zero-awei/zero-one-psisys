#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/22 20:53

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
#ifndef _DEPARTNAMESERVICE_H_
#define _DEPARTNAMESERVICE_H_

#include "../../domain/vo/publicInterfaceVO/DepartVO.h"
#include "../../domain/query/publicInterfaceQuery/DepartNameQuery.h"
#include <list>
class DepartNameService
{
public:
	//列表返回查询数据
	list<DepartVO>listAll(const DepartNameQuery& query);
};

#endif // _DEPARTNAMESERVICE_H_