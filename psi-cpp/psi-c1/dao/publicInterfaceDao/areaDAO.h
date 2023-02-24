#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/18 17:08

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
#ifndef _AREASERVICEDAO_H_
#define _AREASERVICEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/AreaQueryDO.h"
#include "../../domain/do/publicInterfaceDO/AreaReturnDO.h"

class AreaDAO :public BaseDAO
{
public:
	//选择用户查询
	list<AreaReturnDO>selectArea(const AreaQueryDO& obj);
};



#endif // _AREASERVICEDAO_H_