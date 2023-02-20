#include "stdafx.h"
#include "ImportSupplierDAO.h"
#include <sstream>

uint64_t ImportSupplierDAO::insert(const ImportSupplierDO& iObj)
{
    string sql = "INSERT INTO `bas_currency` (`code`, `name`) VALUES (?, ?)";
    return sqlSession->executeInsert(sql, "%s%s", iObj.getCode(), iObj.getName());
}
