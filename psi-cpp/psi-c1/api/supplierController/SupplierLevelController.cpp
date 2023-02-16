#include "stdafx.h"
#include "SupplierLevelController.h"

/*
供应商等级下拉列表
Author C1-三木
2023.2.11 21点35分
*/


JsonVO<list<SupplierLevelVO>> SupplierLevelController::executequerySupplierLevel()
{
    list<SupplierLevelVO> data;
    SupplierLevelVO vo;
    vo.setId(1);
    vo.setName(u8"一级");
    data.push_back(vo);
    JsonVO<list<SupplierLevelVO>> res;
    res.success(data);
    return res;
}
