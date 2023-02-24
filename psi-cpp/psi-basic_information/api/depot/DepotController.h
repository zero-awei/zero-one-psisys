#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Linsky
 @Date: 2023/2/13 20:31:04
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
#ifndef _DEPOT_CONTROLLER_
#define _DEPOT_CONTROLLER_

#include "../../domain/query/depot/DepotQuery.h"
#include "../../domain/dto/depot/DepotDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/depot/DepotVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "service/depot/DepotService.h"
#include "../lib-common/include/ExcelComponent.h"
// #include "../../domain/dto/FileDTO.h"

/**
 * 基础资料仓库模块接口
 */
class DepotController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryDepot, execQueryDepot, DepotQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryKidDepot, execQueryKidDepot, OnlyValueQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailDepot, execQueryDetail, OnlyValueQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryActionInfolDepot, execQueryActionInfo, OnlyValueQuery);
	CREATE_API_FUN_BODY(addDepot, execAddDepot, DepotDTO);
	CREATE_API_FUN_BODY(addKidDepot, execAddKidDepot, DepotDTO);
	CREATE_API_FUN_BODY(modifyDepot, execModifyDepot, DepotDTO);
	CREATE_API_FUN_BODY(removeDepot, execRemoveDepot, OnlyValueQuery);
	// 这里直接用FileDTO报错
	CREATE_API_FUN_BODY_FILE(addDepots, execAddDepots, DepotDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, DepotQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExeclOnly, execExportExeclOnly, OnlyValueQuery);
private:
	//默认查询数据
	JsonVO<PageVO<DepotVO>> execQueryDepot(const DepotQuery& query, const PayloadDTO& payload);
	//查询子级列表
	JsonVO<std::list<DepotVO>> execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload);
	// 查询详情
	JsonVO<DepotDetailVO> execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload);
	JsonVO<DepotActionInfoVO> execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload);
	// 新增仓库
	JsonVO<bool> execAddDepot(const DepotDTO& dto);
	// 新增子级仓库
	JsonVO<bool> execAddKidDepot(const DepotDTO& dto);
	//修改仓库
	JsonVO<bool> execModifyDepot(const DepotDTO& dto);
	//删除仓库 
	JsonVO<bool> execRemoveDepot(const OnlyValueQuery& query);
	//文件导入
	JsonVO<bool> execAddDepots(const DepotDTO& dto);
	//文件导出
	JsonVO<string> execExportExecl(const DepotQuery& query, const PayloadDTO& payload);
	// 通过唯一值批量导出
	JsonVO<string> execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload);
};

#endif // _DEPOT_CONTROLLER_