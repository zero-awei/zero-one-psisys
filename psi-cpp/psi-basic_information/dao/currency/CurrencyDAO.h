#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: douhao
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
#ifndef _CURRENCY_DAO_
#define _CURRENCY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/currency/CurrencyDO.h"

/**
 * 示例表数据库操作实现
 */
class CurrencyDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CurrencyDO& iObj);
	// 分页查询数据
	list<CurrencyDO> selectWithPage(const CurrencyDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 通过姓名查询数据
	list<CurrencyDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const CurrencyDO& iObj);
	// 修改数据
	int update(const CurrencyDO& uObj);
	// 通过ID删除数据
	int deleteById(string code);
	
};
#endif // !_CURRENCY_DAO_
