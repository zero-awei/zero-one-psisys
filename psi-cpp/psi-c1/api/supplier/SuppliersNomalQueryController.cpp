#include "stdafx.h"
#include "SuppliersNomalQueryController.h"

JsonVO<PageVO<SuppliersInfoVO>> SuppliersNomalQueryController::executeQuerySuppliersNomal()
{
    PageVO<SuppliersInfoVO> data;
    JsonVO<PageVO<SuppliersInfoVO>> res;

    res.success(data);

    return res;
}
