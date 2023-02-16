#include "stdafx.h"
#include "PyrkController.h"

JsonVO<uint64_t> PyrkController::execRemovePyrkBillById(const StringID& id)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillStateToClose(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillStateToVoid(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<ImportPyrkFileVO> PyrkController::execImportPyrkFile(const ImportPyrkFileDTO& dto, const PayloadDTO& payload)
{
	JsonVO<ImportPyrkFileVO> result;
	ImportPyrkFileVO vo;
	result.success(vo);
	return result;
}

JsonVO<string> PyrkController::execExportPyrkFile(const StringIDs& ids)
{
	JsonVO<string> result;
	string s = "www.baidu.com";
	result.success(s);
	return result;
}
