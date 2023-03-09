#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kiva
 @Date: 2022/10/25 11:17:48

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

#ifndef _BASWAREHOUSETREEDDAO_H_
#define _BASWAREHOUSETREEDDAO_H_
#include"./BaseDAO.h"
#include"./domain/do/publicInterfaceDO/BasWareHouseTreeDO.h"
class BasWareHouseTreeDAO :public BaseDAO {
public:
    uint64_t count(const BasWareHouseTreeDO& iObj);

    list<BasWareHouseTreeDO> selectWithPage(const BasWareHouseTreeDO& obj, uint64_t pageIndex, uint64_t pageSize);
};

#endif