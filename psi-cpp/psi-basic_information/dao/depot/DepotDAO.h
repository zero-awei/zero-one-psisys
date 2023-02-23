#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _DEPOT_DAO_
#define _DEPOT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/depot/DepotDO.h"
#include "../../domain/vo/depot/DepotVO.h"

/**
 * 仓库数据库操作实现
 */
class DepotDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const DepotDO& iObj);
	// 分页查询数据
	std::list<DepotDO> selectWithPage(const DepotDO& obj, uint64_t pageIndex, uint64_t pageSize);
	std::list<DepotDO> selectKid(const DepotDO& obj);
	// 新建
	int insertDepot(const DepotDO& iObj);
	// 通过ID删除数据
	int deleteDepot(const DepotDO& iObj);
	// 通过ID修改
	int update(const DepotDO& uObj);
};
#endif // !_DEPOT_DAO_
