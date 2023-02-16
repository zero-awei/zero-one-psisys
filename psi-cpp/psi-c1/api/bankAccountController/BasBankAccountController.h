#pragma once
#ifndef _BASBANKACCOUNTCONTROLLEER_H_
#define _BASBANKACCOUNTCONTROLLER_H_
#include"../../domain/vo/JsonVO.h"
#include"../../domain/vo/bankAccountVO/BasBankAccountVO.h"
//#include"api/ApiHelper.h"



class BasBankAccountController {
public:
	CREATE_API_FUN_QUERY3(queryBasBankAccount, execQueryBasBankAccount);


private:
	JsonVO<std::list<BasBankAccountVO>> execQueryBasBankAccount();
};


#endif
