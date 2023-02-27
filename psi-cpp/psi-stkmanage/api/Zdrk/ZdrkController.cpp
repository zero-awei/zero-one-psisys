#include "stdafx.h"
#include "ZdrkController.h"

JsonVO<QueryZdrkBillDetailsVO> ZdrkController::execQueryZdrkBillDetails(const QueryZdrkBillDetailsQuery& query)
{
    ZdrkService service;
    QueryZdrkBillDetailsVO result = service.getZdrkBillDetails(query);
    return JsonVO<QueryZdrkBillDetailsVO>(result, RS_SUCCESS);
}

JsonVO<PageVO<QueryZdrkBillListVO>> ZdrkController::execQueryZdrkBillList(const QueryZdrkBillListQuery& query)
{   
    ZdrkService service;
    PageVO<QueryZdrkBillListVO> result = service.listZdrkBillList(query);
    return JsonVO<PageVO<QueryZdrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> ZdrkController::execAddZdrkBill(const AddZdrkBillDTO& dto)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> ZdrkController::execModifyZdrkBill(const ModifyZdrkBillDTO& dto)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> ZdrkController::execRemoveZdrkBill(const StringID& dto)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> ZdrkController::execModifyZdrkBillState(const ModifyZdrkBillStateDTO& dto)
{
    return JsonVO<uint64_t>();
}

JsonVO<uint64_t> ZdrkController::execImportZdrkFile(const ImportZdrkFileDTO& dto)
{
    return JsonVO<uint64_t>();
}



JsonVO<std::string> ZdrkController::execEmportZdrkFile()
{
    return JsonVO<std::string>();
}


