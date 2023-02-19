#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/19 12:23:49

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
#ifndef _BASMATERIAL_DAO_
#define _BASMATERIAL_DAO_
#include "BaseDAO.h"
#include "../../psi-basic_information/domain/do/BasMaterial/BasMaterialDO.h"

/**
 * 示例表数据库操作实现
 */
class BasMaterialDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const BasMaterialDO& iObj);
	// 分页查询数据
	list<BasMaterialDO> selectWithPage(const BasMaterialDO& obj, uint64_t pageIndex, uint64_t pageSize);
	
	// 通过名称查询数据
	list<BasMaterialDO> selectByName(const string& name);
	// 通过编码查询数据
	list<BasMaterialDO> selectByCode(const string& code);
	// 通过物料分类查询数据
	list<BasMaterialDO> selectByCategoryId(const string& categoryId);

	// 新建物料
	uint64_t insert(const BasMaterialDO& iObj);
	// 修改物料
	int update(const BasMaterialDO& uObj);
	// 通过code编码删除物料
	int deleteById(string id);
};
#endif // !_BASMATERIAL_DAO_
