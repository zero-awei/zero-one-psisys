#pragma once
#ifndef _BASBANKACCOUNTCONTROLLER_H_
#define _BASBANKACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/bank-account/BasBankAccountVO.h"

class BasBankAccountController {
public:
	CREATE_API_FUN_QUERY3(queryBasBankAccount, execQueryBasBankAccount);
private:
	JsonVO<std::list<BasBankAccountVO>> execQueryBasBankAccount();
};


#endif
