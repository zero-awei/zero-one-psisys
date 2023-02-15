#pragma once
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
#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include "domain/dto/pur-req/AddPurReqDTO.h"
#include "domain/dto/pur-req/DeletePurReqDTO.h"
#include "domain/dto/pur-req/ModifyPurReqDTO.h"
#include "domain/dto/pur-req/PurReqModBillStatusDTO.h"
#include "domain/dto/IDDTO.h"
#include "domain/vo/PageVO.h"
#include "domain/vo/JsonVO.h"


class PurReqController
{
public:
	//添加修改删除需要修改人和需求人的信息,所以添加用户信息负载
	//添加订单
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurReq, execAddPurReq, AddPurReqDTO);
	//修改订单
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modifyPurReq, execModifyPurReq, ModifyPurReqDTO);
	//删除订单
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurReqDTO);
	//修改订单状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);

private:
	//新增订单
	JsonVO<uint64_t> execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload);
	//修改订单
	JsonVO<uint64_t> execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload);
	//修改订单状态
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);
	//删除订单
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurReqDTO& id);
};
#endif // _PUR_REQ_CONTROLLER_