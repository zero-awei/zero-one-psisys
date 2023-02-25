#include"stdafx.h"
#include"SupplierCategoryController.h"
#include "../../service/supplierService/SupplierCategoryService.h"

JsonVO<list<SuppliersCategoryVO>>SupplierCategoryController::execQuerySupplierCategory()
{
	list<SuppliersCategoryVO> data;
	SupplierCategoryService service;
	data = service.listAll();
	JsonVO<list<SuppliersCategoryVO>> rs(data, RS_SUCCESS);
	return rs;
}