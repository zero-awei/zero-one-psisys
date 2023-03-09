#include "stdafx.h"
#include "SupplierLevelController.h"
#include "../../service/supplier/SupplierLevelService.h"

/*
供应商等级下拉列表
Author C1-三木
2023.2.11 21点35分
*/


JsonVO<list<SupplierLevelVO>> SupplierLevelController::executequerySupplierLevel()
{
	SupplierLevelService service;
	list<SupplierLevelVO> data = service.listAll();
	JsonVO<list<SupplierLevelVO>> res;
	res.success(data);
	return res;
}
