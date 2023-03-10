#pragma once
#ifndef _CURRENCYTYPE_DO_
#define _CURRENCYTYPE_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class CurrencyTypeDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 货币名
	CC_SYNTHESIZE(string, name, Name);
public:
	CurrencyTypeDO() {
		id = "";
		name = "";
	}
};

#endif // !_CURRENCYTYPE_DO_