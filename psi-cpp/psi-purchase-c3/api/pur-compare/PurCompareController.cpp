/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:57:26

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
#include "PurCompareController.h"
#include "../../service/pur-compare/PurCompareService.h"

JsonVO<PageVO<PurComFindBillVO>> PurCompareController::execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload)
{
	//数据校验
	//定义一个Service
	PurCompareService service;
	//查询数据
	PageVO<PurComFindBillVO> result = service.listPurComFindBill(query);
	//响应结果
	return JsonVO<PageVO<PurComFindBillVO>>(result, RS_SUCCESS);
}

JsonVO<PurComFindDetailBillVO> PurCompareController::execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload)
{
	PurComFindDetailBillVO result;
	//数据校验
	if (query.getBillNo() == "") return JsonVO<PurComFindDetailBillVO>(result, RS_PARAMS_INVALID);
	//定义一个Service
	PurCompareService service;
	//查询数据
	result = service.getPurComFindDetailBill(query);
	//响应结果
	return JsonVO<PurComFindDetailBillVO>(result, RS_SUCCESS);
}

JsonVO<list<PurComListVO>> PurCompareController::execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload)
{
	list<PurComListVO> result;
	//数据校验
	if (query.getBillNo()=="") return JsonVO<list<PurComListVO>>(result, RS_PARAMS_INVALID);
	//定义一个Service
	PurCompareService service;
	//查询数据
	result = service.listPurComList(query);
	//响应结果
	return JsonVO<list<PurComListVO>>(result, RS_SUCCESS);
}

JsonVO<list<PurComDividedListVO>> PurCompareController::execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload)
{
	list<PurComDividedListVO> result;
	//数据校验
	if (query.getBillNo() == "") return JsonVO<list<PurComDividedListVO>>(result, RS_PARAMS_INVALID);
	//定义一个Service
	PurCompareService service;
	//查询数据
	result = service.listPurComDividedList(query);
	//响应结果
	return JsonVO<list<PurComDividedListVO>>(result, RS_SUCCESS);
}

//演示新增比价
JsonVO<uint64_t> PurCompareController::execAddPurCom(const AddPurComDTO& dto, PayloadDTO payload)
{
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.savePurCom(dto, payload);
	if (id > 0)
	{
		result.success(id);
	}
	else
	{
		result.fail(id);
	}

	return result;
}
//演示修改比价
JsonVO<uint64_t> PurCompareController::execModifyPurCom(const ModPurComDTO& dto, PayloadDTO payload) {
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.updatePurCom(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}

	return result;
}
//演示删除比价
JsonVO<uint64_t> PurCompareController::execRemovePurCom(const DelPurComDTO& dto) {
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.removePurCom(dto);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	return result;
}
//演示修改单据状态
JsonVO<uint64_t> PurCompareController::execPurComModBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload) {
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.updatePurComBillStatus(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}

	return result;
}

