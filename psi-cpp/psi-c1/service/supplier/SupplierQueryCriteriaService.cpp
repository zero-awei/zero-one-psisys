#include "stdafx.h"
#include "SupplierQueryCriteriaService.h"
#include "../../dao/supplier/SupplierQueryCriteriaDAO.h"

list<SupplierQueryCriteriaVO> SupplierQueryCriteriaService::listAll()
{
    SupplierQueryCriteriaDAO dao;
    list<SupplierQueryCriteriaDO> result = dao.selectSupplierQueryCriteria();
    list<SupplierQueryCriteriaVO> vr;

    for (SupplierQueryCriteriaDO sub : result)
    {
        SupplierQueryCriteriaVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}