#include "stdafx.h"
#include "SupplierLevelService.h"
#include "../../dao/supplierDao/SupplierLevelDAO.h"

list<SupplierLevelVO> SupplierLevelService::listAll()
{
    SupplierLevelDAO dao;
    list<SupplierLevelDO> result = dao.selectSupplierLevel();
    list<SupplierLevelVO> vr;

    for (SupplierLevelDO sub : result)
    {
        SupplierLevelVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}
