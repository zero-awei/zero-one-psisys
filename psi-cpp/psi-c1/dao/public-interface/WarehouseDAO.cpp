#include "stdafx.h"
#include "WarehouseDAO.h"
#include "WarehouseMapper.h"
#include <sstream>

list<WarehouseDO> WarehouseDAO::selectWarehouse()
{
	stringstream sql;
	sql << "SELECT id,aux_name FROM bas_warehouse";
	string sqlStr = sql.str();
	WarehouseMapper mapper;
	return sqlSession->executeQuery<WarehouseDO, WarehouseMapper>(sqlStr, mapper);
}
