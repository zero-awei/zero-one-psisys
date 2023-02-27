#include "stdafx.h"
#include <sstream>
#include "SuppliersNameDAO.h"
#include "SuppliersNameMapper.h"

std::list<SuppliersNameDO> SuppliersNameDAO::SelectMaterialType()
{
	stringstream sql;
	sql << "SELECT * FROM bas_supplier";
	string sqlStr = sql.str();
	SuppliersNameMapper mapper;
	return sqlSession->executeQuery<SuppliersNameDO, SuppliersNameMapper>(sqlStr, mapper);
  
}
