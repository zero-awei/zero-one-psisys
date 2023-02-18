/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/17 11:13:11

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
#include "stdafx.h"
#include "PurOrderService.h"
//#include "../../dao/PurOrder/PurOrderDAO.h"

// 分页查询所有数据
PageVO<PurOrderVO> PurOrderService::listAll(const PurOrderQuery& query)
{
	//构建返回对象
	PageVO<PurOrderVO> pages;

	return pages;
}

// 查询单个数据
PurOrderVO PurOrderService::getData(uint64_t id)
{
	PurOrderVO data;

	return data;
}

// 保存数据
uint64_t PurOrderService::saveData(const PurOrderDTO& dto)
{
	//组装数据
	//PurOrderDO data;

	//return dao.insert(data);
	return 1;
}

// 修改数据
bool PurOrderService::updateData(const PurOrderDTO& dto)
{
	return true;
}

// 通过ID删除数据
bool PurOrderService::removeData(uint64_t id)
{
	return true;
}
