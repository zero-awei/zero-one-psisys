#include "stdafx.h"
#include "PyrkController.h"

JsonVO<uint64_t> PyrkController::execRemovePyrkBillById(const StringID& id)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillState(const ModifyPyrkBillStateDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	uint64_t data = dto.getToState();
	result.success(data);
	return result;
}
