#include"stdafx.h"
#include"SupplierCategoryController.h"

JsonVO<list<SuppliersCategoryVO>>SupplierCategoryController::execQuerySupplierCategory(const SupplierCategoryQuery& query, const PayloadDTO& payload)
{
	JsonVO<list<SuppliersCategoryVO>>rs;
	list<SuppliersCategoryVO>data;
	rs.success(data);
	return rs;
}