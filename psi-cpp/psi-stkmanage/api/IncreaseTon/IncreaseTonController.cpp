#include "stdafx.h"
#include "IncreaseTonController.h"




JsonVO<QueryDocVO> IncreaseTonController::execQueryDocIncreaseTon(const QueryDocQuery& query, const PayloadDTO& payload)
{
    return JsonVO<QueryDocVO>();
}

JsonVO<PageVO<DoclVO>> IncreaseTonController::execQueryDocListIncreaseTon(const QueryDocListQuery& query, const PayloadDTO& payload)
{
    return JsonVO<PageVO<DoclVO>>();
}

JsonVO<SucVO> IncreaseTonController::execAddDocIncreaseTon(const DocDTO& dto)
{
    return JsonVO<SucVO>();
}

JsonVO<SucVO> IncreaseTonController::execModifyDocIncreaseTon(const DocDTO& dto)
{
    return JsonVO<SucVO>();
}

JsonVO<SucVO> IncreaseTonController::execRemoveDocIncreaseTon(const DocNoDTO& dto)
{
    return JsonVO<SucVO>();
}

JsonVO<SucVO> IncreaseTonController::execModifyDocStatIncreaseTon(const DocStatDTO& dto)
{
    return JsonVO<SucVO>();
}

JsonVO<SucVO> IncreaseTonController::execImportDocFileIncreaseTon(const DocFileDTO& dto)
{
    return JsonVO<SucVO>();
}

JsonVO<SucVO> IncreaseTonController::execEmportDocFileIncreaseTon()
{
    return JsonVO<SucVO>();
}
