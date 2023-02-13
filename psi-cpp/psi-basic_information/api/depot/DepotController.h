#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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

/**
 * 基础资料仓库模块接口
 */
class SampleController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryDepot, execQueryDepot, DepotQuery);
	CREATE_API_FUN_BODY(addDepot, execAddDepot, DepotDTO);
	CREATE_API_FUN_BODY(modifyDepot, execModifyDepot, DepotDTO);
	CREATE_API_FUN_BODY(removeDepot, execRemoveDepot, DepotDTO);
	CREATE_API_FUN_BODY_FILE(modifyDepots, execModifyDepots, DepotDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, DepotQuery);
private:
	//默认查询数据
	JsonVO<PageVO<DepotVO>> execQueryDepot(const DepotQuery& query, const PayloadDTO& payload);
	//查询子级列表 没写完,暂时复制的默认查询
	JsonVO<DepotVO> execQueryKidDepot(const DepotQuery& query, const PayloadDTO& payload);
	// 查询详情
	
	//新增仓库 添加下级应该可以通过这个来实现，就先不写
	JsonVO<uint64_t> execAddDepot(const DepotDTO& dto);
	//修改仓库
	JsonVO<uint64_t> execModifyDepot(const DepotDTO& dto);
	//删除仓库 这里应该传个唯一值就行，反正是对应删除的
	JsonVO<uint64_t> execRemoveDepot(const DepotDTO& dto);
	//文件导入
	JsonVO<DepotVO> execModifyDepots(const DepotDTO& dto);
	//文件导出
	JsonVO<string> execExportExecl(const DepotQuery& query, const PayloadDTO& payload);
};

#endif // _DEPOT_CONTROLLER_
