#include "stdafx.h"
#include "RtvController.h"

JsonVO<PageVO<RtvShowVO>> RtvController::execRtvQuery(const DocListQuery& query)
{
    PageVO<RtvShowVO> result;
    return JsonVO<PageVO<RtvShowVO>>(result, RS_FAIL);
}

JsonVO<PageVO<RtvCheckVO>> RtvController::execRtvEntryQuery(const DocListQuery& query)
{
    PageVO<RtvCheckVO> result;
    return JsonVO<PageVO<RtvCheckVO>>(result, RS_SUCCESS);
}
