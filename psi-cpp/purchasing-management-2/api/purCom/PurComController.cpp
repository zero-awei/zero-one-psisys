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
#include "../../service/purCom/PurComService.h"

// 查询list数据
// 负责人：J4nnA
JsonVO<PageVO<PurComVO>> PurComController::execListPurCom(const PurComQuery& query, const PayloadDTO& payload) {
	// 定义一个Service
	PurComService service;
	// 查询数据
	PageVO<PurComVO> result = service.listAll(query);
	// 响应结果
	return JsonVO<PageVO<PurComVO>>(result, RS_SUCCESS);
}


// 查询指定比价单的明细列表
// 负责人：J4nnA
JsonVO<PageVO<PurComEntryVO>> PurComController::execListPurComEntrys(const PurComEntryQuery& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PurComService service;
	// 查询数据
	PageVO<PurComEntryVO> result = service.listEntry(query);

	// 响应结果
	return JsonVO<PageVO<PurComEntryVO>>(result, RS_SUCCESS);
}

// 查询询价单分录列表
// 负责人：c3阿坤
JsonVO<list<PurOrderDividedListVO>> PurComController::execQueryPurOrderDividedList(const PurOrderDividedListQuery& query, const PayloadDTO& payload) {
	//构建返回对象
	list<PurOrderDividedListVO> result;
	
	//数据校验
	if (query.getBillNo() == "") return JsonVO<list<PurOrderDividedListVO>>(result, RS_PARAMS_INVALID);

	//数据校验成功,返回对应的对象
	PurComService service;
	result = service.listPurOrderDividedListDO(query);

	return JsonVO<list<PurOrderDividedListVO>>(result, RS_SUCCESS);
}