/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
@Date: 2023/02/16 0:23:02

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
#include "PurReqController.h"
#include "../../service/purReq/PurReqService.h"

// 查询list分页数据
JsonVO<PageVO<PurReqVO>> PurReqController::execListPurReq(const PurReqQuery& query, const PayloadDTO& payload) {
	// 定义一个Service
	PurReqService service;
	// 查询数据
	PageVO<PurReqVO> result = service.listAll(query);
	// 响应结果
	return JsonVO<PageVO<PurReqVO>>(result, RS_SUCCESS);
}

// 查询单个数据
JsonVO<PurReqVO> PurReqController::execGetPurReq(const PurReqQuery& query)
{
	PurReqService service;
	JsonVO<PurReqVO> result = JsonVO(service.getData(query.getId()), RS_SUCCESS);
	return result;
}

// 查询list数据
JsonVO<list<PurReqVO>> PurReqController::execListPurReqList(const PurReqQuery& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PurReqService service;
	// 查询数据
	list<PurReqVO> result = service.listAllData(query);
	// 响应结果
	return JsonVO<list<PurReqVO>>(result, RS_SUCCESS);
}