#include "stdafx.h"
#include "TaxScaleService.h"
#include "../../dao/publicInterfaceDao/TaxScaleDAO.h"

list<TaxScaleVO> TaxScaleService::listAll()
{
    TaxScaleDAO dao;
    list<TaxScaleDO> result = dao.selectTaxScale();
    list<TaxScaleVO> vr;

    for (TaxScaleDO sub : result)
    {
        TaxScaleVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}
