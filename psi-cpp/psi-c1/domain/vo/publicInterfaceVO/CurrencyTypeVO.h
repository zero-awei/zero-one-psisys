#pragma once

#ifndef _CURRENCY_TYPE_VO_
#define _CURRENCY_TYPE_VO_

#include "../../GlobalInclude.h"

class CurrencyTypeVO
{
	CC_SYNTHESIZE(int, id, Id);
	CC_SYNTHESIZE(string, name, Name);
public:
	BIND_TO_JSON(CurrencyTypeVO, id, name);
};
#endif // !CURRENCY_TYPE_VO
