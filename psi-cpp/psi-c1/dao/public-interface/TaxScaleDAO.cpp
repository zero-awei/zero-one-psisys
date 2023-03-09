#include "stdafx.h"
#include "TaxScaleDAO.h"
#include "TaxScaleMapper.h"
#include <sstream>


list<TaxScaleDO> TaxScaleDAO::selectTaxScale()
{
	stringstream sql;
	sql << "SELECT * FROM sys_dict_item where dict_id=1244653717570326530";
	string sqlStr = sql.str();
	TaxScaleMapper mapper;
	return sqlSession->executeQuery<TaxScaleDO, TaxScaleMapper>(sqlStr, mapper);
}
