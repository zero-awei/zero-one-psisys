#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/14 18:35:30

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




#include "../../domain/query/MaterialClassification/MaterialClassificationQuery.h"
#include "../../domain/dto/MaterialClassification/MaterialClassificationDTO.h"
#include "../../domain/vo/MaterialClassification/MaterialClassificationVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"


/**
 * 示例控制器，演示基础接口的使用
 */
class MaterialClassificationController
{
public:
	CREATE_API_FUN_QUERY(queryMaterialClassification, execQueryMaterialClassification, MaterialClassificationQuery);
	CREATE_API_FUN_QUERY(queryMaterialClassificationChild, execQueryMaterialClassificationChild,MaterialClassificationQuery);
	CREATE_API_FUN_QUERY(queryMaterialClassificationDetail, execQueryMaterialClassificationDetail,MaterialClassificationQuery);
	CREATE_API_FUN_BODY_PAYLOAD(addMaterialClassification, execAddMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyMaterialClassification, execModifyMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY(removeMaterialClassification, execRemoveMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY_FILE(importMaterialClassification, execImportMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportMaterialClassification, execExportMaterialClassification, StringIDs);
private:

	//普通（分页）查询
	JsonVO<PageVO<MaterialClassificationBaseVO>> execQueryMaterialClassification(const MaterialClassificationQuery& query);

	//查询子级列表   暂时先不分页显示
	JsonVO<list<MaterialClassificationChildVO>> execQueryMaterialClassificationChild(const MaterialClassificationQuery& query);
	
	//查询指定分类详细信息
	JsonVO<list<MaterialClassificationDetailVO>> execQueryMaterialClassificationDetail(const MaterialClassificationQuery& query);


	//新增分类 ,添加、修改、删除下级应该也可以用这种方式  #返回的是id,但是数据库用的是varchar
	JsonVO<uint64_t> execAddMaterialClassification(const MaterialClassificationDTO& dto, const PayloadDTO& payload);
	//修改分类
	JsonVO<uint64_t> execModifyMaterialClassification(const MaterialClassificationDTO& dto, const PayloadDTO& payload);
	//删除分类
	JsonVO<uint64_t> execRemoveMaterialClassification(const MaterialClassificationDTO& dto);
	
	//文件导入
	JsonVO<int> execImportMaterialClassification(const MaterialClassificationDTO& dto);
	//文件导出
	JsonVO<string> execExportMaterialClassification(const StringIDs& IDs, const PayloadDTO& payload);
};

