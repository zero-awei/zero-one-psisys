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