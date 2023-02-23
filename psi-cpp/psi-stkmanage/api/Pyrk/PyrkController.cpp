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
	else if (id == -1) {
		result.setData(id);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(id);
	}
	return result;
}

JsonVO<int> PyrkController::execModifyBillApproval(const ApprovalDTO& approval, const PayloadDTO& payload)
{
	JsonVO<int> result;
	// 定义一个Service
	PyrkService service;
	// 执行修改数据(审核)
	int id = service.updateApproval(approval, payload);
	if (id > 0) {
		result.success(id);
	}
	else if (id == -1) {
		result.setData(id);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(id);
	}
	return result;
}

JsonVO<int> PyrkController::execUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage, const PayloadDTO& payload) {
	JsonVO<int> result;
	// 定义一个Service
	PyrkService service;
	// 执行修改盘盈入库单据
	int id = service.updateBillData(updateMessage, payload);
	if (id > 0) {
		result.success(id);
	}
	else if (id == -1) {
		result.setData(id);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(id);
	}
	return result;
}

JsonVO<int> PyrkController::execRemovePyrkBillById(const StringID& id)
{
	JsonVO<int> result;
	int data = 0;
	result.success(data);
	return result;
}

JsonVO<int> PyrkController::execModifyPyrkBillStateToClose(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<int> result;
	int data = 0;
	result.success(data);
	return result;
}

JsonVO<int> PyrkController::execModifyPyrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<int> result;
	int data = 0;
	result.success(data);
	return result;
}

JsonVO<int> PyrkController::execModifyPyrkBillStateToVoid(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<int> result;
	int data = 0;
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
