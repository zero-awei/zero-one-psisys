#pragma once
#ifndef _DELETEACCOUNTCONTROLLER_H_
#define _DELETEACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/bank-account/BankAccountDTO.h"
#include "../../domain/dto/IDDTO.h"

/*
* ÕË»§É¾³ý
* @Author: Oxygen
* @Date: 2023/2/14 16:35:27
*/
class DeleteAccountController
{
public:
	CREATE_API_FUN_BODY(removeBankAccount, execRemoveBankAccount, StringID);
private:
	JsonVO<std::string> execRemoveBankAccount(const StringID& id);
};

#endif // _DELETEACCOUNTCONTROLLER_H_