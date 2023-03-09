#include "stdafx.h"
#include "TaxRateService.h"
#include "../../dao/public-interface/TaxRateDAO.h"

list<TaxRateVO> TaxRateService::listAll()
{
    TaxRateDAO dao;
    list<TaxRateDO> result = dao.selectTaxRate();
    list<TaxRateVO> vr;

    for (TaxRateDO sub : result)
    {
        TaxRateVO vo;
        vo.setId(sub.getId());
        vo.setRate(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}