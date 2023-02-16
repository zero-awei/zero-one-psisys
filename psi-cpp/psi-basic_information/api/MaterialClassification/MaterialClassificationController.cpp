
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/14 20:21:24

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
#include "MaterialClassificationController.h"


JsonVO<PageVO<MaterialClassificationBaseVO>> MaterialClassificationController::execQueryMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<MaterialClassificationBaseVO>> rs;
	PageVO<MaterialClassificationBaseVO> data;
	list<MaterialClassificationBaseVO> rows;
	rows.push_back(MaterialClassificationBaseVO());
	rows.push_back(MaterialClassificationBaseVO());
	rows.push_back(MaterialClassificationBaseVO());
	
	data.setRows(rows);
	rs.success(data);

	//响应结果
	return rs;
}

JsonVO<MaterialClassificationChildVO> MaterialClassificationController::execQueryMaterialClassificationChild(const MaterialClassificationChildQuery& query, const PayloadDTO& payload)
{

	JsonVO<MaterialClassificationChildVO> result;
	//响应结果
	return JsonVO<MaterialClassificationChildVO>(result);
}

JsonVO<MaterialClassificationDetailVO> MaterialClassificationController::execQueryMaterialClassificationDetail(const MaterialClassificationDetailQuery& query, const PayloadDTO& payload)
{

	//响应结果
	return JsonVO<MaterialClassificationDetailVO>();
}

JsonVO<AddMaterialClassificationVO> MaterialClassificationController::execAddMaterialClassification(const MaterialClassificationDTO& dto)
{
	JsonVO<AddMaterialClassificationVO> result;
	
	//响应结果
	return result;
}

JsonVO<MaterialClassificationBaseVO> MaterialClassificationController::execModifyMaterialClassification(const MaterialClassificationDTO& dto)
{
	
	JsonVO<MaterialClassificationBaseVO> result;
	
	return result;
}

JsonVO<MaterialClassificationBaseVO> MaterialClassificationController::execRemoveMaterialClassification(const MaterialClassificationDTO& dto)
{
	
	JsonVO<MaterialClassificationBaseVO> result;
	//响应结果
	return result;
}

//文件导入
JsonVO<PageVO<MaterialClassificationBaseVO>> MaterialClassificationController::execImportMaterialClassification(const MaterialClassificationDTO& dto) {
	JsonVO<PageVO<MaterialClassificationBaseVO>> result;
	//响应结果
	return result;
}

JsonVO<string> MaterialClassificationController::execExportMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload) {
	JsonVO<string> result;
	//响应结果
	return result;
}
