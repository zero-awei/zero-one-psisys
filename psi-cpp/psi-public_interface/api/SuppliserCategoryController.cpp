#include"stdafx.h"
#include"SupplierCategoryController.h"

JsonVO<list<SuppliersCategoryVO>>SupplierCategoryController::execQuerySupplierCategory(const SupplierCategoryQuery& query, const PayloadDTO& payload)
{
	JsonVO<list<SuppliersCategoryVO>>rs;
	list<SuppliersCategoryVO>data;
	data.push_back(SuppliersCategoryVO());
	data.push_back(SuppliersCategoryVO());
	data.push_back(SuppliersCategoryVO());
	rs.success(data);
	return rs;
}