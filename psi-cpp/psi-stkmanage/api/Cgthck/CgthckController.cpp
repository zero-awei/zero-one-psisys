#include "stdafx.h"
#include "CgthckController.h"

JsonVO<PageVO<QueryCgthckBillVO>> CgthckController::execQueryCgthckBill(const QueryCgthckBillQuery& query)
{
    // 定义一个service
    CgthckService service;
    // 查询数据
    PageVO<QueryCgthckBillVO> result = service.listAll(query);
    return JsonVO<PageVO<QueryCgthckBillVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<QueryCgthckBillDetailVO>> CgthckController::execQueryCgthckBillDetail(const QueryCgthckBillQuery& query)
{
    PageVO<QueryCgthckBillDetailVO> result;
    list<QueryCgthckBillDetailVO> rows;
    rows.push_back(QueryCgthckBillDetailVO());
    result.setRows(rows);
    return JsonVO<PageVO<QueryCgthckBillDetailVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<QueryCgrkBillListsVO>> CgthckController::execQueryCgrkBillList(const QueryCgrkBillQuery& query)
{
    return JsonVO<PageVO<QueryCgrkBillListsVO>>();
}

JsonVO<uint64_t> CgthckController::execAddCgthckBill(const AddCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    CgthckService service;
    // 执行数据新增
    uint64_t res = service.saveData(dto);
    if (res > 0)
    {
        result.success(res);
    }
    else if (res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckBill(const AddCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    CgthckService service;
    // 执行数据修改
    int res = service.updateData(dto);
    if (res > 0)
    {
        result.success(res);
    }
    else if (res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    CgthckService service;
    // 执行数据修改
    int res = service.updateApproval(dto, payload);
    if (res > 0)
    {
        result.success(res);
    }
    else if(res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthcStatusToClose(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> CgthckController::execModifyCgthcStatusToUnclose(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> CgthckController::execModifyCgthcStatusToVoided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> CgthckController::execDeleteCgthckBill(const DeleteCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execImportCgthckFile(const ImportCgthckFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execExportCgthckFile(const ExportCgthckFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}
