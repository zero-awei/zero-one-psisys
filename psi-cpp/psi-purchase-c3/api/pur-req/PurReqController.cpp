/*
 Copyright Zero One Star. All rights reserved.

 @Author: Adam
 @Date: 2023年2月15日

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

//新增订单
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改订单
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改订单状态
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto,  const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//删除订单
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}

