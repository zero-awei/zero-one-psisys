#include "stdafx.h"
#include "CurrencyTypeController.h"
#include "../../service/public-interface/CurrencyTypeService.h"

JsonVO<list<CurrencyTypeVO>> CurrencyTypeController::execQueryCurrencyType()
{
	CurrencyTypeService service;
	list<CurrencyTypeVO> data = service.listAll();
	JsonVO<list<CurrencyTypeVO>> res;
	res.success(data);
	return res;
}
