#include "stdafx.h"
#include "RtvController.h"

JsonVO<PageVO<RtvShowVO>> RtvController::execRtvQuery(const DocListQuery& query)
{
    PageVO<RtvShowVO> result;
    return JsonVO<PageVO<RtvShowVO>>(result, RS_FAIL);
}
