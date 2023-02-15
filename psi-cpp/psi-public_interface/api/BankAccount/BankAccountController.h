#pragma once
#ifndef _BANKACCOUNTACONTROLLER_H_
#define _BANKACCOUNTACONTROLLER_H_
#include"../../domain/vo/JsonVO.h"
#include"../../domain/vo/BankAccount/SpecifiedBankAccountListVO.h"
#include"../../domain/query/BankAccount/SpecifiedBankAccountQuery.h"
#include"../../domain/vo/PageVO.h"
class BankAccountController {
public:
	CREATE_API_FUN_QUERY(querySpecifiedBankAccount, execSpecifiedBankAccount, SpecifiedBankAccountQuery);


private:
	JsonVO<PageVO<SpecifiedBankAccountListVO>> execSpecifiedBankAccount(SpecifiedBankAccountQuery& query);
};


#endif