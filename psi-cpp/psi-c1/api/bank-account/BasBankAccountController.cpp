#include "stdafx.h"
#include "BasBankAccountController.h"
#include "../../service/public-interface/BasBankAccountService.h"

JsonVO<std::list<BasBankAccountVO>> BasBankAccountController::execQueryBasBankAccount()
{
    list<BasBankAccountVO> data;
	BasBankAccountService service;
	//查询数据
	list<BasBankAccountVO> result = service.listAll();
	//响应结果
	return JsonVO<list<BasBankAccountVO>>(result, RS_SUCCESS);
}
