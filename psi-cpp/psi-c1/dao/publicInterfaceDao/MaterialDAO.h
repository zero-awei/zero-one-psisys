#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/21 22:17

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
#ifndef _MATERIALDAO_H_
#define _MATERIALDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/MaterialReturnDO.h"
#include "../../domain/do/publicInterfaceDO/MaterialQueryDO.h"

class MaterialDAO :public BaseDAO
{
public:
	//查询物料信息
	list<MaterialReturnDO>selecMaterialWithPage(const MaterialQueryDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//用于统计一个查询里可以返回的表项数量
	uint64_t count(const MaterialQueryDO& iObj);
};

#endif // _MATERIALDAO_H_