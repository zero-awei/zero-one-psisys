#include "stdafx.h"
#include "CurrencyTypeDAO.h"
#include "CurrencyTypeMapper.h"
#include <sstream>


list<CurrencyTypeDO> CurrencyTypeDAO::selectCurrencyType()
{
	stringstream sql;
	sql << "SELECT * FROM bas_currency";
	string sqlStr = sql.str();
	CurrencyTypeMapper mapper;
	return sqlSession->executeQuery<CurrencyTypeDO, CurrencyTypeMapper>(sqlStr, mapper);
}
