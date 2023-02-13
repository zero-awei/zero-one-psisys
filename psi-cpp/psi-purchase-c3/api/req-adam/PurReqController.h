#pragma once
#ifndef _REQADAM_CONTROLLER_
#define _REQADAM_CONTROLLER_

#include "../../domain/dto/req-adam/PurReqDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


class ReqAdamController
{
public:
	//添加订单
	CREATE_API_FUN_BODY(addPurReq, execAddPurReq, PurReqDTO);
	//修改订单
	CREATE_API_FUN_BODY(modifyPurReq, execModifyPurReq, PurReqDTO);
	//删除订单
	CREATE_API_FUN_BODY(removePurReq, execRemovePurReq, PurReqDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);

	//修改订单状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(modifyPurReqState, execModifyPurReqState, PurReqDTO);
private:
	//演示新增数据
	JsonVO<uint64_t> execAddPurReq(const PurReqDTO& dto);
	//演示修改数据
	JsonVO<uint64_t> execModifyPurReq(const PurReqDTO& dto);
	//演示修改状态
	JsonVO<uint64_t> execModifyPurReqState(const PurReqDTO& dto);
	//演示删除数据
	JsonVO<uint64_t> execRemovePurReq(const PurReqDTO& dto);
	JsonVO<uint64_t> execRemoveById(const IntID& id);
};
#endif // _REQADAM_CONTROLLER_