#pragma once
#ifndef _PUR_REQ_ADAM_CONTROLLER_
#define _PUR_REQ_ADAM_CONTROLLER_

#include "../../domain/dto/pur-req-adam/PurReqAdamDTO.h"
#include "../../domain/vo/pur-req-adam/PurReqAdamVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


class PurReqAdamController
{
public:
	//添加订单
	CREATE_API_FUN_BODY(addPurReq, execAddPurReq, AddAndModifyPurReqDTO);
	//修改订单
	CREATE_API_FUN_BODY(modifyPurReq, execModifyPurReq, AddAndModifyPurReqDTO);
	//删除订单
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurDTO);
	//修改订单状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);
private:
	//新增订单
	JsonVO<uint64_t> execAddPurReq(const AddAndModifyPurReqDTO& dto);
	//修改订单
	JsonVO<uint64_t> execModifyPurReq(const AddAndModifyPurReqDTO& dto);
	//修改订单状态
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto);
	//删除订单
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurDTO& id);
};
#endif // _PUR_REQ_ADAM_CONTROLLER_