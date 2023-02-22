#include "stdafx.h"
#include "PyrkController.h"
#include "../../service/Pyrk/PyrkService.h"



JsonVO<PageVO<QueryPyrkBillListVO>> PyrkController::execQueryBillList(const QueryPyrkBillListQuery& query)
{
    PageVO<QueryPyrkBillListVO> result;
    return JsonVO<PageVO<QueryPyrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<QueryPyrkDetailedBillVO> PyrkController::exeQueryBillDetailed(const QueryPyrkBillListQuery& query) {
    QueryPyrkDetailedBillVO result;
    return JsonVO<QueryPyrkDetailedBillVO>(result, RS_SUCCESS);
}

JsonVO<int> PyrkController::execAddBillDetailed(const PyrkBillDetailDTO& addMessage, const PayloadDTO& payload) 
{
	JsonVO<int> result;
	// 定义一个Service
	PyrkService service;
	// 执行新增数据
	int id = service.saveBillData(addMessage, payload);
	if (id > 0) {
		result.success(id);
	}
	else if (id <= 0) {
		result.setData(id);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(id);
	}
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyBillApproval(const ApprovalDTO& approval, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	// 定义一个Service
	PyrkService service;
	// 执行修改数据(审核)
	uint64_t id = service.updateApproval(approval, payload);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	return result;
}

JsonVO<uint64_t> PyrkController::execUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage, const PayloadDTO& payload) {
    return JsonVO<uint64_t>(0, RS_SUCCESS);
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
