#include "stdafx.h"
#include "CurrencyTypeController.h"

JsonVO<list<CurrencyTypeVO>> CurrencyTypeController::execQueryCurrencyType()
{
	list<CurrencyTypeVO> data;
	CurrencyTypeVO vo;
	vo.setId(1);
	vo.setName(u8"»À√˚±“");
	data.push_back(vo);
	JsonVO<list<CurrencyTypeVO>> res;
	res.success(data);
	return res;
}
