#include "stdafx.h"
#include "SupplierCategoryDAO.h"
#include "SupplierCategoryMapper.h"


std::list<SupplierCategoryReturnDO> SupplierCategoryDAO::selectSupplierCategory()
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT distinct supplier_category";
	sql << " FROM bas_supplier";
	sql << " WHERE not supplier_category is NULL";
	SupplierCategoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SupplierCategoryReturnDO, SupplierCategoryMapper>(sqlStr, mapper, params);
}
