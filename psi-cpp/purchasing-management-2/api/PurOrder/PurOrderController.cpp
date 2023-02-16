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
#include "PurOrderController.h"
// #include "../../service/PurOrder/PurOrderSerive.h"

JsonVO<PageVO<PurOrderVO>> PurOrderController::execListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	//return JsonVO<PageVO<SampleVO>>(result, RS_SUCCESS);
	JsonVO<PageVO<PurOrderVO>> result = JsonVO<PageVO<PurOrderVO>>();
	return  result;
}

JsonVO<PurOrderVO> PurOrderController::execGetPurOrder(const IntID& id)
{
	JsonVO<PurOrderVO> result;

	return result;
}

// 新增数据
JsonVO<uint64_t> PurOrderController::execAddPurOrder(const PurOrderDTO& dto)
{
	JsonVO<uint64_t> result;

	return result;
}
// 修改数据
JsonVO<uint64_t> PurOrderController::execModifyPurOrder(const PurOrderDTO& dto)
{
	JsonVO<uint64_t> result;

	return result;
}
//删除数据
JsonVO<uint64_t> PurOrderController::execRemovePurOrder(const PurOrderDTO& dto)
{
	JsonVO<uint64_t> result;

	return result;
}
// 删除数据-ID
JsonVO<uint64_t> PurOrderController::execRemoveById(const IntID& id)
{
	JsonVO<uint64_t> result;

	return result;
}