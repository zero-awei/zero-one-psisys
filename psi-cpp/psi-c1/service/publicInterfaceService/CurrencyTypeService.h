#pragma once

#ifndef _CURRENCY_TYPE_SERVICE_
#define _CURRENCY_TYPE_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/CurrencyTypeVO.h"


class CurrencyTypeService
{
public:
	//查询货币类型列表
	list<CurrencyTypeVO> listAll();
};
#endif // !_CURRENCY_TYPE_SERVICE_
