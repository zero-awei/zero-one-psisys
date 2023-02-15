#include "stdafx.h"
#include "DepotController.h"

JsonVO<PageVO<DepotVO>> DepotController::execQueryDepot(const DepotQuery& query, const PayloadDTO& payload)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<DepotVO> DepotController::execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotVO>();
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotDetailVO>();
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotActionInfoVO>();
}

JsonVO<PageVO<DepotVO>> DepotController::execAddDepot(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execModifyDepot(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execRemoveDepot(const OnlyValueQuery& query)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execAddDepots(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

