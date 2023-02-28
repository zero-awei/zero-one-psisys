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
#ifndef _MATERIALCLASSIFICATION_SERVICE_
#define _MATERIALCLASSIFICATION_SERVICE_
#include "../../domain/vo/MaterialClassification/MaterialClassificationVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/MaterialClassification/MaterialClassificationQuery.h"
#include "../../domain/dto/MaterialClassification/MaterialClassificationDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../lib-common/include/SnowFlake.h"
#include "../../domain/dto/IDDTO.h"
/**
 * 物料分类服务实现，演示基础的示例服务实现
 */
class MaterialClassificationService
{
public:
	// 分页查询所有数据 #计划在父类里面嵌套子类
	PageVO<MaterialClassificationBaseVO> listAll(const MaterialClassificationQuery& query);

	//查询子类列表
	list<MaterialClassificationChildVO> listChildren(const MaterialClassificationQuery& query);

	//查询指定分类详细信息
	list<MaterialClassificationDetailVO> listDetail(const MaterialClassificationQuery& query);
	// 保存数据
	int saveData(const MaterialClassificationDTO& dto, const string& userName);
	// 修改数据
	int updateData(const MaterialClassificationDTO& dto, const PayloadDTO& payload);
	// 通过ID删除数据
	int removeData(const MaterialClassificationDTO& dto);

	//导入数据
	int importData(const MaterialClassificationDTO& dto);

	//导出数据
	string exportData(const string& id, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_

