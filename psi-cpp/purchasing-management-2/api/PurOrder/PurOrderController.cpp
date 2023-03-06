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

// 删除采购订单
// 负责人：Andrew
JsonVO<string> PurOrderController::execRemoveById(const StringID& id)
{
	// 数据校验
	if (id.getId() == "") return JsonVO<string>({}, RS_PARAMS_INVALID);
	PurOrderDTO dto;
	dto.setId(id.getId());

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

// 新增数据
JsonVO<uint64_t> PurOrderController::execAddPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//定义一个Service
	PurOrderService service;

	//执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.setStatus(RS_SUCCESS);
	}
	else if (id == -1)
	{
		result.setStatus(RS_PARAMS_INVALID); // 9995
		return result;
	}
	else
	{
		result.setStatus(RS_FAIL); // 9999
	}
	return result;
}
// 修改数据
JsonVO<uint64_t> PurOrderController::execModifyPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	//定义一个Service
	PurOrderService service;

	JsonVO<uint64_t> result;
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		result.setStatus(RS_SUCCESS);
	}
	else if (id == -1)
	{
		result.setStatus(RS_PARAMS_INVALID); // 9995
		return result;
	}
	else
	{
		result.setStatus(RS_FAIL); // 9999
	}
	return result;
}

// 查询list数据
JsonVO<PageVO<PurOrderVO>> PurOrderController::execQueryListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload)
{
	PurOrderService service;
	PageVO<PurOrderVO> result = service.listPurOrder(query);
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

// 查询单个数据byDTO
JsonVO<PurOrderDetailVO> PurOrderController::execGetPurOrder(const PurOrderQuery& query)
{
	PurOrderService service;
	PurOrderDetailVO result = service.getPurOrder(query);
	if (result.getBill_no().empty()) return  JsonVO(result, RS_FAIL);
	JsonVO<PurOrderDetailVO> jsresult = JsonVO(result, RS_SUCCESS);

	return jsresult;
}