#include "stdafx.h"
#include "BasMaterialController.h"
#include <service/BasMaterial/BasMaterialService.h>

/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/23 10:58:42

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
JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	BasMaterialService service;
	//查询数据
	PageVO<BasMaterialVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
JsonVO<BasMaterialVO> BasMaterialController::execQueryDetail(const BasMaterialDetailQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	BasMaterialService service;
	//查询数据
	BasMaterialVO result = service.getData(query);
	//响应结果
	return JsonVO<BasMaterialVO>(result, RS_SUCCESS);

}
JsonVO<uint64_t> BasMaterialController::execAddBasMaterial(const BasMaterialDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	BasMaterialService service;
	//cout << 1 << dto.getAuxName();
	//执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//响应结果
	return result;
}


JsonVO<uint64_t> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto, const PayloadDTO& payload)
{
	BasMaterialService service;
	JsonVO<uint64_t> result;
	if (service.updateData(dto, payload)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}

//删除
JsonVO<uint64_t> BasMaterialController::execRemoveBasMaterial(const BasMaterialDTO& dto)
{
	BasMaterialService service;
	JsonVO<uint64_t> result;
	//执行数据删除
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//响应结果
	return result;
}

JsonVO<uint64_t> BasMaterialController::execRemoveById(const IntID& id)
{
	BasMaterialDTO dto;
	dto.setId(id.getId());
	return execRemoveBasMaterial(dto);
}

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execImportBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<string> BasMaterialController::execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<string>();
}
