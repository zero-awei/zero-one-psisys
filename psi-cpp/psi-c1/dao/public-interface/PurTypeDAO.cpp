#include "stdafx.h"
#include "PurTypeDAO.h"
#include "PurTypeMapper.h"
#include <sstream>

list<PurTypeDO> PurTypeDAO::selectPurType()
{
	stringstream sql;
	sql << "SELECT * FROM sys_dict_item where dict_id=1531294400602177537";
	string sqlStr = sql.str();
	PurTypeMapper mapper;
	return sqlSession->executeQuery<PurTypeDO, PurTypeMapper>(sqlStr, mapper);
}
