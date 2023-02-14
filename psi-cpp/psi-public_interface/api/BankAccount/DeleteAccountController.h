#pragma once

#ifndef _DELETEACCOUNTCONTROLLER_H_
#define _DELETEACCOUNTCONTROLLER_H_
#include "domain/vo/JsonVO.h"
#include "domain/dto/BankAccountVO/BankAccountDTO.h"
#include "api/ApiHelper.h"

/*
* ÕË»§É¾³ý
* @Author: Oxygen
* @Date: 2023/2/14 16:35:27
*/
class DeleteAccountController
{
public:
	CREATE_API_FUN_BODY(removeBankAccount, execRemoveBankAccount, BankAccountDTO);
private:
	JsonVO<uint64_t> execRemoveBankAccount(const BankAccountDTO& dto);
};

#endif // _DELETEACCOUNTCONTROLLER_H_