#pragma once
#ifndef _PUR_REQ_ADAM_CONTROLLER_
#define _PUR_REQ_ADAM_CONTROLLER_

#include "../../domain/dto/pur-req-adam/PurReqAdamDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


class PurReqAdamController
{
public:
	//添加修改删除需要修改人和需求人的信息,所以添加用户信息负载
	//添加订单
	CREATE_API_FUN_BODY_PAYLOAD(addPurReq, execAddPurReq, AddAndModifyPurReqDTO);
	//修改订单
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReq, execModifyPurReq, AddAndModifyPurReqDTO);
	//删除订单
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurDTO);
	//修改订单状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);
private:
	//新增订单
	JsonVO<uint64_t> execAddPurReq(const AddAndModifyPurReqDTO& dto, const PayloadDTO& payload);
	//修改订单
	JsonVO<uint64_t> execModifyPurReq(const AddAndModifyPurReqDTO& dto, const PayloadDTO& payload);
	//修改订单状态
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);
	//删除订单
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurDTO& id);
};
#endif // _PUR_REQ_ADAM_CONTROLLER_