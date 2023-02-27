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
#include "PurComController.h"
#include "../../service/PurCom/PurComService.h"

// 查询list数据
JsonVO<PageVO<PurComVO>> PurComController::execListPurCom(const PurComQuery& query, const PayloadDTO& payload) {
	// 定义一个Service
	PurComService service;
	// 查询数据
	PageVO<PurComVO> result = service.listAll(query);
	// 响应结果
	return JsonVO<PageVO<PurComVO>>(result, RS_SUCCESS);
}

// 查询单个数据
JsonVO<PurComVO> PurComController::execGetPurCom(const PurComQuery& query)
{
	PurComService service;
	//JsonVO<PurComVO> result = JsonVO(service.getData(query.getId()), RS_SUCCESS);
	//return result;
	JsonVO<PurComVO> result;
	return result;
}
