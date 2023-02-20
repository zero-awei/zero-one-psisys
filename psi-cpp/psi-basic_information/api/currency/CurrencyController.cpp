#include "stdafx.h"
#include "CurrencyController.h"

JsonVO<PageVO<CurrencyVO>> CurrencyController::execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<CurrencyDetailVO> CurrencyController::execQueryDetail(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<CurrencyDetailVO>();
}

JsonVO<CurrencyActionInfoVO> CurrencyController::execQueryActionInfo(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<CurrencyActionInfoVO>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execAddCurrency(const CurrencyDTO& dto)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execModifyCurrency(const CurrencyDTO& dto)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execRemoveCurrency(const OnlyValueCurrencyQuery& query)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execAddCurrencys(const CurrencyDTO& dto)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<string> CurrencyController::execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> CurrencyController::execExportExeclOnly(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}