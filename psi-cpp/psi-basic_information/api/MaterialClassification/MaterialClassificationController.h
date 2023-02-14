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



/**
 * 示例控制器，演示基础接口的使用
 */
class MaterialClassificationController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterialClassification, execQueryMaterialClassification, MaterialClassificationQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterialClassificationChild, execQueryMaterialClassificationChild,MaterialClassificationChildQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterialClassificationDetail, execQueryMaterialClassificationDetail,MaterialClassificationDetailQuery);
	CREATE_API_FUN_BODY(addMaterialClassification, execAddMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY(modifyMaterialClassification, execModifyMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY(removeMaterialClassification, execRemoveMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY_FILE(importMaterialClassification, execImportMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportMaterialClassification, execExportMaterialClassification, MaterialClassificationQuery);
private:

	//普通查询
	JsonVO<PageVO<MaterialClassificationVO>> execQueryMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload);

	//查询子级列表   暂时先不分页显示
	JsonVO<MaterialClassificationVO> execQueryMaterialClassificationChild(const MaterialClassificationChildQuery& query, const PayloadDTO& payload);
	
	//查询指定分类详细信息
	JsonVO<MaterialClassificationVO> execQueryMaterialClassificationDetail(const MaterialClassificationDetailQuery& query, const PayloadDTO& payload);


	//新增分类
	JsonVO<MaterialClassificationVO> execAddMaterialClassification(const MaterialClassificationDTO& dto);
	//修改分类
	JsonVO<MaterialClassificationVO> execModifyMaterialClassification(const MaterialClassificationDTO& dto);
	//删除分类
	JsonVO<MaterialClassificationVO> execRemoveMaterialClassification(const MaterialClassificationDTO& dto);
	
	//文件导入
	JsonVO<PageVO<MaterialClassificationVO>> execImportMaterialClassification(const MaterialClassificationDTO& dto);
	//文件导出
	JsonVO<string> execExportMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload);
};

