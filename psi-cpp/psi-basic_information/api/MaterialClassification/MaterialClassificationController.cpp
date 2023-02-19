
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
#include"../../service/MaterialClassification/MaterialClassificationService.h"


JsonVO<PageVO<MaterialClassificationBaseVO>> MaterialClassificationController::execQueryMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	MaterialClassificationService service;
	//查询数据
	PageVO<MaterialClassificationBaseVO> result = service.listAll(query);
	//响应结果
	
	//数据校验
	if (query.getCode() == "") 
		return JsonVO<PageVO< MaterialClassificationBaseVO>>({}, RS_PARAMS_INVALID);
	
	return JsonVO<PageVO< MaterialClassificationBaseVO>>(result, RS_SUCCESS);

}

JsonVO<MaterialClassificationChildVO> MaterialClassificationController::execQueryMaterialClassificationChild(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	MaterialClassificationService service;

	//查询子级数据
	JsonVO<MaterialClassificationChildVO> result;
	//响应结果


	return JsonVO<MaterialClassificationChildVO>(result);
}

JsonVO<MaterialClassificationDetailVO> MaterialClassificationController::execQueryMaterialClassificationDetail(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{

	//定义一个Service
	MaterialClassificationService service;

	//查询详细数据（感觉就是编辑那里）
	JsonVO<MaterialClassificationChildVO> result;

	//响应结果
	return JsonVO<MaterialClassificationDetailVO>();
}

JsonVO<uint64_t> MaterialClassificationController::execAddMaterialClassification(const MaterialClassificationDTO& dto)
{
	JsonVO<uint64_t> result;
	MaterialClassificationService service;
	//执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//响应结果

	if (dto.getCode() == "")
		return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
	return result;
}

JsonVO<string> MaterialClassificationController::execModifyMaterialClassification(const MaterialClassificationDTO& dto)
{
	
	MaterialClassificationService service;
	JsonVO<string> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}

	if (dto.getCode() == "")
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	return result;
	
}

JsonVO<string> MaterialClassificationController::execRemoveMaterialClassification(const MaterialClassificationDTO& dto)
{
	
	MaterialClassificationService service;
	JsonVO<string> result;
	//执行数据删除
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//响应结果
	if (dto.getCode() == "")
		return JsonVO<string>({}, RS_PARAMS_INVALID);
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
