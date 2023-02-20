#include "stdafx.h"
#include "ZdrkController.h"

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

JsonVO<uint64_t> ZdrkController::execAddZdrkBill(const AddZdrkBillDTO& dto)
{

    JsonVO<uint64_t> result;
    result.success(1);
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


