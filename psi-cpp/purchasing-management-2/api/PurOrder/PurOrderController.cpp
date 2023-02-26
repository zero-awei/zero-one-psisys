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
#include "../lib-common/include/CharsetConvertHepler.h"

// 查询list数据
JsonVO<PageVO<PurOrderVO>> PurOrderController::execListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload)
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

	JsonVO<PurOrderVO> result = JsonVO(service.getData(dto.getId()), RS_SUCCESS);
	test.setId(dto.getId());
	result = JsonVO(test, RS_SUCCESS);

	return result;
}

// 新增数据
JsonVO<string> PurOrderController::execAddPurOrder(const PurOrderDTO& dto)
{
	JsonVO<string> result;
	//定义一个Service
	PurOrderService service;

	//执行数据新增
	string id = service.saveData(dto);
	if (id != "") {
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
JsonVO<string> PurOrderController::execModifyPurOrder(const PurOrderDTO& dto)
{
	//定义一个Service
	PurOrderService service;

	JsonVO<string> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}

// 修改单据状态
// 负责人：Andrew
JsonVO<string> PurOrderController::execStatusPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if (dto.getId().empty() || dto.getBill_no().empty()) // 如果id或者单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// 如果操作类型未知
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.UNCLOSE && dto.getOpType() != dto.CANCEL)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	JsonVO<string> result;
	PurOrderService service;

	if (service.updateStatus(dto, payload)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭成功"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭成功"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废成功"));
			break;
		}
	}
	else
	{
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭失败"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭失败"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废失败"));
			break;
		}
	}
	return result;
}
//删除数据
JsonVO<string> PurOrderController::execRemovePurOrder(const PurOrderDTO& dto)
{
	//定义一个Service
	PurOrderService service;

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
	return result;
}

// 删除数据byId
// 负责人：Andrew
JsonVO<string> PurOrderController::execRemoveById(const StringID& id)
{
	// 数据校验
	if (id.getId() == "") return JsonVO<string>({}, RS_PARAMS_INVALID);
	PurOrderDTO dto;
	dto.setId(id.getId());
	return execRemovePurOrder(dto);
}