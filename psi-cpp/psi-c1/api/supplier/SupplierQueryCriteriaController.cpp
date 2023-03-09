#include "stdafx.h"
#include "SupplierQueryCriteriaController.h"
#include "../../service/supplier/SupplierQueryCriteriaService.h"
/*
供应商高级查询条件下拉列表
Author C1-三木
*/

JsonVO<list<SupplierQueryCriteriaVO>> SupplierQueryCriteriaController::executequerySupplierQueryCriteria()
{
	SupplierQueryCriteriaService service;
	list<SupplierQueryCriteriaVO> data = service.listAll();
	JsonVO<list<SupplierQueryCriteriaVO>> res;
	res.success(data);
	return res;
}
