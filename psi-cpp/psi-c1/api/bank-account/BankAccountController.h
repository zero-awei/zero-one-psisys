#pragma once
#ifndef _BANKACCOUNTACONTROLLER_H_
#define _BANKACCOUNTACONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/bank-account/SpecifiedBankAccountListVO.h"
#include "../../domain/query/bank-account/SpecifiedBankAccountQuery.h"
#include "../../domain/vo/bank-account/BankAccountListVO.h"
#include "../../domain/query/bank-account/BankAccountQuery.h"

class BankAccountController {
public:
	CREATE_API_FUN_QUERY(querySpecifiedBankAccount, execSpecifiedBankAccount, SpecifiedBankAccountQuery);
	CREATE_API_FUN_QUERY(queryBankAccountList, executequeryBankAccountList, BankAccountQuery);
private:
	JsonVO<PageVO<SpecifiedBankAccountListVO>> execSpecifiedBankAccount(SpecifiedBankAccountQuery& query);
	JsonVO<PageVO<BankAccountListVO>> executequeryBankAccountList(BankAccountQuery& query);
};


#endif