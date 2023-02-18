#include "stdafx.h"
#include "CgthckController.h"

JsonVO<PageVO<QueryCgthckBillVO>> CgthckController::execQueryCgthckBill(const QueryCgthckBillQuery& query)
{
    PageVO<QueryCgthckBillVO> result;
    list<QueryCgthckBillVO> rows;
    rows.push_back(QueryCgthckBillVO());
    rows.push_back(QueryCgthckBillVO());
    rows.push_back(QueryCgthckBillVO());
    result.setRows(rows);
    return JsonVO<PageVO<QueryCgthckBillVO>>(result, RS_FAIL);
}

JsonVO<PageVO<QueryCgthckBillDetailVO>> CgthckController::execQueryCgthckBillDetail(const QueryCgthckBillQuery& query)
{
    PageVO<QueryCgthckBillDetailVO> result;
    list<QueryCgthckBillDetailVO> rows;
    rows.push_back(QueryCgthckBillDetailVO());
    result.setRows(rows);
    return JsonVO<PageVO<QueryCgthckBillDetailVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> CgthckController::execAddCgthckBill(const AddCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckBill(const ModifyCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
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
