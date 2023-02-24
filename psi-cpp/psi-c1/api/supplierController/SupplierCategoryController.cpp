#include"stdafx.h"
#include"SupplierCategoryController.h"
#include "../../service/supplierService/SupplierCategoryService.h"

JsonVO<list<SuppliersCategoryVO>>SupplierCategoryController::execQuerySupplierCategory(const SupplierCategoryQuery& query, const PayloadDTO& payload)
{
	list<SuppliersCategoryVO> data;
	SupplierCategoryService service;
	data = service.listAll(query);
	JsonVO<list<SuppliersCategoryVO>> rs(data, RS_SUCCESS);
	return rs;
}