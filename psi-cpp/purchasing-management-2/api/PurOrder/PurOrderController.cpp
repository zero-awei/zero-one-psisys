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
#include "../../service/PurOrder/PurOrderService.h"

// 查询list数据
JsonVO<PageVO<PurOrderVO>> PurOrderController::execQueryPurOrder(const PurOrderQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	PurOrderService service;
	//查询数据
	//PageVO<PurOrderVO> result = service.listAll(query);
	// 测试
	PageVO<PurOrderVO> result;
	list<PurOrderVO> rows;
	rows.push_back(PurOrderVO());
	rows.push_back(PurOrderVO());
	result.setRows(rows);
	//响应结果
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

// 查询单个数据byDTO
JsonVO<PurOrderVO> PurOrderController::execGetPurOrder(const PurOrderDTO& dto)
{
	PurOrderService service;
	PurOrderVO test;

	JsonVO<PurOrderVO> result = JsonVO(service.getPurOrder(dto.getId()), RS_SUCCESS);
	test.setId(dto.getId());
	result = JsonVO(test, RS_SUCCESS);

	return result;
}

// 新增数据
JsonVO<uint64_t> PurOrderController::execAddPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//定义一个Service
	PurOrderService service;

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
	return result;
}
// 修改数据
JsonVO<uint64_t> PurOrderController::execModifyPurOrder(const PurOrderDTO& dto)
{
	//定义一个Service
	PurOrderService service;

	JsonVO<uint64_t> result;
	service.updateData(dto);
	/*if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}*/
	return result;
}

// 修改状态
JsonVO<uint64_t> PurOrderController::execStatusPurOrder(const PurOrderDTO& dto)
{
	JsonVO<uint64_t> result;
	PurOrderService service;

	return result;
}
//删除数据
JsonVO<uint64_t> PurOrderController::execRemovePurOrder(const PurOrderDTO& dto)
{
	//定义一个Service
	PurOrderService service;

	JsonVO<uint64_t> result;
	//执行数据删除
	//if (service.removeData(dto.getId())) {
	//	result.success(dto.getId());
	//}
	//else
	//{
	//	result.fail(dto.getId());
	//}
	//响应结果
	return result;
}
//删除数据byId
JsonVO<uint64_t> PurOrderController::execRemoveById(const IntID& id)
{
	PurOrderDTO dto;
	//dto.setId(id.getId());
	return execRemovePurOrder(dto);
}