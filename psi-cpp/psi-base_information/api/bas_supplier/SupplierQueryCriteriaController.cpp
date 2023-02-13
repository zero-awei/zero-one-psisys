#include "stdafx.h"
#include "SupplierQueryCriteriaController.h"

/*
供应商高级查询条件下拉列表
Author C1-三木
2023.2.13 21点54分
*/

JsonVO<list<SupplierQueryCriteriaVO>> SupplierQueryCriteriaController::executequerySupplierQueryCriteria()
{
    list<SupplierQueryCriteriaVO> data;
    SupplierQueryCriteriaVO vo;
    vo.setId(1);
    vo.setName(u8"供应商分类");
    data.push_back(vo);
    JsonVO<list<SupplierQueryCriteriaVO>> res;
    res.success(data);
    return res;
}
