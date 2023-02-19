#include "stdafx.h"
#include "PyrkController.h"



JsonVO<PageVO<QueryPyrkBillListVO>> PyrkController::execQueryBillList(const QueryPyrkBillListQuery& query)
{
    PageVO<QueryPyrkBillListVO> result;
    return JsonVO<PageVO<QueryPyrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<QueryPyrkDetailedBillVO> PyrkController::exeQueryBillDetailed(const QueryPyrkBillListQuery& query) {
    QueryPyrkDetailedBillVO result;
    return JsonVO<QueryPyrkDetailedBillVO>(result, RS_SUCCESS);
}

JsonVO<int> PyrkController::exeAddBillDetailed(const PyrkBillDetailDTO& addMessage) {
    return JsonVO<int>(1, RS_SUCCESS);
}

JsonVO<int> PyrkController::exeUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage) {
    return JsonVO<int>(1, RS_SUCCESS);
}

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
