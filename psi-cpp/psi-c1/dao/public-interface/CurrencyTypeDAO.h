#pragma once
#ifndef _CURRENCYTYPE_DAO_
#define _CURRENCYTYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-interface/CurrencyTypeDO.h"

class CurrencyTypeDAO : public BaseDAO
{
public:
	// 查询货币类型
	list<CurrencyTypeDO> selectCurrencyType();
};
#endif // !_CURRENCYTYPE_DAO_