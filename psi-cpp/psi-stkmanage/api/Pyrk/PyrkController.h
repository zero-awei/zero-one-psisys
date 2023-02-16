#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/Pyrk/ModifyPyrkBillStateDTO.h"

/**
* 盘盈入库控制器
*/
class PyrkController
{
public:
	CREATE_API_FUN_BODY(removePyrkBillById, execRemovePyrkBillById, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillState, execModifyPyrkBillState, ModifyPyrkBillStateDTO);
private:
	//删除单据
	JsonVO<uint64_t> execRemovePyrkBillById(const StringID& id);
	//修改单据状态
	JsonVO<uint64_t> execModifyPyrkBillState(const ModifyPyrkBillStateDTO& dto, const PayloadDTO& payload);
};



#endif // !_PYRK_CONTROLLER_