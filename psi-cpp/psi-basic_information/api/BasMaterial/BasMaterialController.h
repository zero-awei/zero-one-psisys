#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/25 20:40

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
#ifndef _BASMATERIAL_CONTROLLER_
#define _BASMATERIAL_CONTROLLER_

#include "../../domain/query/BasMaterial/BasMaterialQuery.h"
#include "../../domain/dto/BasMaterial/BasMaterialDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/BasMaterial/BasMaterialVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * 示例控制器，演示基础接口的使用
 */
class BasMaterialController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryBasMaterial, execQueryBasMaterial, BasMaterialQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailBasMaterial, execQueryDetail, BasMaterialQuery);
	CREATE_API_FUN_BODY(addBasMaterial, execAddBasMaterial, BasMaterialDTO);
	CREATE_API_FUN_BODY(modifyBasMaterial, execModifyBasMaterial, BasMaterialDTO);
	CREATE_API_FUN_BODY(removeBasMaterial, execRemoveBasMaterial, BasMaterialDTO);
	CREATE_API_FUN_BODY_FILE(importBasMaterial, execImportBasMaterial, BasMaterialDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, BasMaterialQuery);
private:
	//普通查询数据
	JsonVO<PageVO<BasMaterialVO>> execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload);
	//查看指定物料详情信息
	JsonVO<BasMaterialVO> execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload);
	//新增数据
	JsonVO<BasMaterialVO> execAddBasMaterial(const BasMaterialDTO& dto);
	//修改数据
	JsonVO<BasMaterialVO> execModifyBasMaterial(const BasMaterialDTO& dto);
	//删除数据
	JsonVO<BasMaterialVO> execRemoveBasMaterial(const BasMaterialDTO& dto);
	//导入
	JsonVO<PageVO<BasMaterialVO>> execImportBasMaterial(const BasMaterialDTO& dto);
	//导出
	JsonVO<string> execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload);
};

#endif // _BASMATERIAL_CONTROLLER_