
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


JsonVO<PageVO<MaterialClassificationVO>> MaterialClassificationController::execQueryMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{
	
	//响应结果
	return JsonVO<PageVO<MaterialClassificationVO>>();
}

JsonVO<MaterialClassificationVO> MaterialClassificationController::execQueryMaterialClassificationChild(const MaterialClassificationChildQuery& query, const PayloadDTO& payload)
{
	JsonVO<MaterialClassificationVO> result;
	//响应结果
	return JsonVO<MaterialClassificationVO>(result);
}

JsonVO<MaterialClassificationVO> MaterialClassificationController::execQueryMaterialClassificationDetail(const MaterialClassificationDetailQuery& query, const PayloadDTO& payload)
{

	//响应结果
	return JsonVO<MaterialClassificationVO>();
}

JsonVO<MaterialClassificationVO> MaterialClassificationController::execAddMaterialClassification(const MaterialClassificationDTO& dto)
{
	JsonVO<MaterialClassificationVO> result;
	
	//响应结果
	return result;
}

JsonVO<MaterialClassificationVO> MaterialClassificationController::execModifyMaterialClassification(const MaterialClassificationDTO& dto)
{
	
	JsonVO<MaterialClassificationVO> result;
	
	return result;
}

JsonVO<MaterialClassificationVO> MaterialClassificationController::execRemoveMaterialClassification(const MaterialClassificationDTO& dto)
{
	
	JsonVO<MaterialClassificationVO> result;
	//响应结果
	return result;
}

//文件导入
JsonVO<PageVO<MaterialClassificationVO>> MaterialClassificationController::execImportMaterialClassification(const MaterialClassificationDTO& dto) {
	JsonVO<PageVO<MaterialClassificationVO>> result;
	//响应结果
	return result;
}

JsonVO<string> MaterialClassificationController::execExportMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload) {
	JsonVO<string> result;
	//响应结果
	return result;
}
