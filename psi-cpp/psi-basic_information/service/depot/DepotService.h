#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _DEPOT_SERVICE_
#define _DEPOT_SERVICE_
#include <list>
#include "../../domain/vo/depot/DepotVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/depot/DepotQuery.h"
#include "../../domain/dto/depot/DepotDTO.h"
#include "../../domain/do/depot/DepotDO.h"
#include "../../dao/depot/DepotDAO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DepotService
{
public:
	// 分页查询所有数据
	PageVO<DepotVO> listAll(const DepotQuery& query);
	// 查询所以子级
	std::list<DepotVO> getKid(const OnlyValueQuery& query);
	// 保存数据
	int saveData(const DepotDTO& dto);
	// 保存子级数据
	int saveKidData(const DepotDTO& dto);
	// 删除数据
	bool removeData(const OnlyValueQuery& query);
	int modifyDepot(const DepotDTO& dto);
	// 导入文件
	bool saveFile(const std::list<DepotDTO>& dto);
};

#endif // !_DEPOT_SERVICE_

