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
#ifndef _Measurement_DAO_
#define _Measurement_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Measurement/MeasurementDO.h"

/**
 * 数据库操作实现
 */
class MeasurementDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MeasurementDO& iObj);
	// 分页查询数据
	list<MeasurementDO> selectWithPage(const MeasurementDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询指定单位子级列表
	list<MeasurementDO> selectKidData(const string& id);
	// 通过Id查询数据
	list<MeasurementDO> selectById(const string& id);
	//通过pid查询数据
	list<MeasurementDO> selectByPid(const string& pid);
	// 通过名称查询数据
	list<MeasurementDO> selectByName(const string& name);
	// 插入数据
	int insert(const MeasurementDO& iObj);
	// 修改数据
	int update(const MeasurementDO& uObj);
	//修改新增之后的has_child
	int updateHas_child(const int& count, const string& id);
	//新增子级列表更新pid
	int updatePid(const string& pid, const string& id);
	// 通过名称删除数据
	int deleteById(const string& id);
	//通过pid删除数据
	int deleteByPid(const string& pid);
	// 导入文件
	uint64_t ImportFile(const MeasurementImportFileDO& iObj);
	//导出文件
	list<MeasurementDO> selectExportFile(const string& obj);
};
#endif // !_Measurement_DAO_
