#include "stdafx.h"
#include "ZdrkController.h"
#include "../psi-stkmanage/service/Zdrk/ZdrkService.h"
JsonVO<PageVO<QueryZdrkBillDetailsVO>> ZdrkController::execQueryZdrkBillDetails(const QueryZdrkBillDetailsQuery& query)
{
    PageVO<QueryZdrkBillDetailsVO> result;
    list<QueryZdrkBillDetailsVO> rows;
    rows.push_back(QueryZdrkBillDetailsVO());
    result.setRows(rows);
    return JsonVO<PageVO<QueryZdrkBillDetailsVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<QueryZdrkBillListVO>> ZdrkController::execQueryZdrkBillList(const QueryZdrkBillListQuery& query)
{
    PageVO<QueryZdrkBillListVO> result;
    list<QueryZdrkBillListVO> rows;
    rows.push_back(QueryZdrkBillListVO());
    rows.push_back(QueryZdrkBillListVO());
    rows.push_back(QueryZdrkBillListVO());
    result.setRows(rows);
    return JsonVO<PageVO<QueryZdrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> ZdrkController::execAddZdrkBill(const AddZdrkBillDTO& dto,const  PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    // 定义一个Service
    ZdrkService service;
    // 执行新增数据
    int id = service.saveBillData(dto, payload);
    cout << id << endl;
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

JsonVO<int> ZdrkController::execModifyBillApproval(const ApprovalDTO& approval, const PayloadDTO& payload)
{
    JsonVO<int> result;
    // 定义一个Service
    ZdrkService service;
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

JsonVO<int> ZdrkController::execModifyZdrkBill(const ModifyZdrkBillDTO& dto , const PayloadDTO& payload)
{
    JsonVO<int> result;
    // 定义一个Service
    ZdrkService service;
    // 执行修改盘盈入库单据
    int id = service.updateBillData(dto, payload);
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

JsonVO<int> ZdrkController::execRemoveZdrkBill(const StringID& dto)
{
    JsonVO<int> result;
    // 定义一个Service
    ZdrkService service;
    // 执行删除单据
    int ret = service.removeBillById(dto.getId());
    if (ret == 1) {
        result.success(ret);
    }
    else {
        result.fail(ret);
    }
    return result;
}

JsonVO<uint64_t> ZdrkController::execModifyZdrkBillState(const ModifyZdrkBillStateDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<int> ZdrkController::execModifyZdrkBillStateToClose(const StringID& id, const PayloadDTO& payload)
{
    JsonVO<int> result;
    // 定义一个Service
    ZdrkService service;
    // 执行关闭单据
    int ret = service.updateStateToClose(id.getId(), payload);
    if (ret > 0) {
        result.success(ret);
    }
    else {
        result.fail(ret);
    }
    return result;
}

JsonVO<int> ZdrkController::execModifyZdrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload)
{
    JsonVO<int> result;
    // 定义一个Service
    ZdrkService service;
    // 执行关闭单据
    int ret = service.updateStateToUnclose(id.getId(), payload);
    if (ret > 0) {
        result.success(ret);
    }
    else {
        result.fail(ret);
    }
    return result;
}

JsonVO<int> ZdrkController::execModifyZdrkBillStateToVoid(const StringID& id, const PayloadDTO& payload)
{
    JsonVO<int> result;
    // 定义一个Service
    ZdrkService service;
    // 执行关闭单据
    int ret = service.updateStateToVoid(id.getId(), payload);
    if (ret > 0) {
        result.success(ret);
    }
    else {
        result.fail(ret);
    }
    return result;
}

JsonVO<uint64_t> ZdrkController::execImportZdrkFile(const ImportZdrkFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<std::string> ZdrkController::execEmportZdrkFile()
{
    JsonVO<std::string> result;
    result.success("1");
    return result;
}


