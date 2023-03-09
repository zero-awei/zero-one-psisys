#include "stdafx.h"
#include "TaxRateDAO.h"
#include "TaxRateMapper.h"
#include <sstream>

list<TaxRateDO> TaxRateDAO::selectTaxRate()
{
	stringstream sql;
	sql << "SELECT * FROM sys_dict_item where dict_id=1528751882899582977";
	string sqlStr = sql.str();
	TaxRateMapper mapper;
	return sqlSession->executeQuery<TaxRateDO, TaxRateMapper>(sqlStr, mapper);
}
