#include "stdafx.h"
#include "SupplierLevelDAO.h"
#include "SupplierLevelMapper.h"
#include <sstream>

list<SupplierLevelDO> SupplierLevelDAO::selectSupplierLevel()
{
	stringstream sql;
	sql << "SELECT * FROM sys_dict_item where dict_id=1244548790885990401";
	string sqlStr = sql.str();
	SupplierLevelMapper mapper;
	return sqlSession->executeQuery<SupplierLevelDO, SupplierLevelMapper>(sqlStr, mapper);
}
