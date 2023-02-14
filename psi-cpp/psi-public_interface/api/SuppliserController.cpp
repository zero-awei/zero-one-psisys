#include"stdafx.h"
#include"SupplierController.h"

JsonVO<list<SuppliersVO>>SupplierController::execQuerySupplier(const SupplierQuery& query, const PayloadDTO& payload)
{
	JsonVO<list<SuppliersVO>>rs;
	list<SuppliersVO>data;
	rs.success(data);
	return rs;
}