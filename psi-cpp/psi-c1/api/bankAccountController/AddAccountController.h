#pragma once

#ifndef _ADDACCOUNTCONTROLLER_H_
#define _ADDACCOUNTCONTROLLER_H_
#include "domain/vo/JsonVO.h"
#include "../../domain/dto/bankAccountDTO/BankAccountDTO.h"
#include "api/ApiHelper.h"

/*
* ÕË»§Ìí¼Ó
* @Author: Oxygen
* @Date: 2023/2/13 20:55:58
*/
class AddAccountController
{
public:
	CREATE_API_FUN_BODY_PAYLOAD(addBankAccount, execAddBankAccount, BankAccountDTO);
private:
	JsonVO<uint64_t> execAddBankAccount(const BankAccountDTO& dto, const PayloadDTO& pdto);
};

#endif // _ADDACCOUNTCONTROLLER_H_