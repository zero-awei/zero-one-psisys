#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/18 11:08:56

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
#ifndef _AREASERVICE_H_
#define _AREASERVICE_H_

#include <list>
#include "../../domain/vo/public-interface/AreaVO.h"
#include "../../domain/query/public-interface/AreaQuery.h"

class AreaService
{
public:
	//列表返回查询数据
	list<AreaVO>listAll(const AreaQuery& query);
};

#endif // _AREASERVICE_H_