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

JsonVO<uint64_t> ZdrkController::execModifyZdrkBill(const ModifyZdrkBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> ZdrkController::execRemoveZdrkBill(const StringID& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> ZdrkController::execModifyZdrkBillState(const ModifyZdrkBillStateDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
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


