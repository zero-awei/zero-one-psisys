#include "stdafx.h"
#include "ImportSupplierDAO.h"
#include <sstream>

uint64_t ImportSupplierDAO::insert(const ImportSupplierDO& iObj)
{
    string sql = "INSERT INTO `bas_supplier` (`id`, `code`, `name`, `short_name`, `aux_name`, `supplier_category`, `supplier_level`, `is_enabled`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%ull%s%s%s%s%s%s%i", iObj.getId(), iObj.getCode(), iObj.getName(), 
        iObj.getShortName(), iObj.getAuxName(), iObj.getSupplierCategory(), iObj.getSupplierLevel(), iObj.getIsEnabled());
}
