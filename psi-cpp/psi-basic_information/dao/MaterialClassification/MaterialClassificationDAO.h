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
#ifndef _MATERIALCLASSIFICATION_DAO_
#define _MATERIALCLASSIFICATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MaterialClassification/MaterialClassificationDO.h"

/**
 * 示例表数据库操作实现
 */
 /**
  * 示例表数据库操作实现
  */
class MaterialClassificationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MaterialClassificationDO& iObj);
	// 分页查询数据
	list<MaterialClassificationDO> selectWithPage(const string& pid, uint64_t pageIndex, uint64_t pageSize);
	// 通过姓名查询数据
	list<MaterialClassificationDO> selectByName(const string& name);

	// 通过编码查询数据 #后面再加
	list<MaterialClassificationDO> selectByCode(const string& code);

	// 通过父节点查询数据,可以用来查询子级列表
	list<MaterialClassificationDO> selectByPid(const string& pid);

	//通过id查询数据
	list<MaterialClassificationDO> selectById(const string& id);

	// 插入数据
	uint64_t insert(const MaterialClassificationDO& iObj);
	// 修改数据
	int update(const MaterialClassificationDO& uObj);
	//通过id修改是否有子类的项
	int updateHasChildById(const string& id, const string child);
	// 通过ID删除数据
	int deleteById(string id);
	//通过pid删除数据
	int deleteByPid(string pid);
	//应该还有个导入数据
};
#endif 
