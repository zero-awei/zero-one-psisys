#pragma once

#ifndef _ADDACCOUNTCONTROLLER_H_
#define _ADDACCOUNTCONTROLLER_H_
#include "domain/vo/JsonVO.h"
#include "domain/dto/BankAccountVO/BankAccountDTO.h"
#include "api/ApiHelper.h"

/*
* ÕË»§Ìí¼Ó
* @Author: Oxygen
* @Date: 2023/2/13 20:55:58
*/
class AddAccountController
{
public:
	CREATE_API_FUN_BODY(addBankAccount, execAddBankAccount, BankAccountDTO);
private:
	JsonVO<uint64_t> execAddBankAccount(const BankAccountDTO& dto);
};

#endif // _ADDACCOUNTCONTROLLER_H_