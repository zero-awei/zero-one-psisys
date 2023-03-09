#pragma once

#ifndef _EDITACCOUNTCONTROLLER_H_
#define _EDITACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/bank-account/BankAccountDTO.h"

/*
* 账户信息修改
* @Author: Oxygen
* @Date: 2023/2/14 16:24:07
*/
class EditAccountController
{
public:
	CREATE_API_FUN_BODY_PAYLOAD(modifyBankAccount, execModifyBankAccount, BankAccountDTO);
private:
	JsonVO<std::string> execModifyBankAccount(const BankAccountDTO& dto, const PayloadDTO& pdto);
};

#endif // _EDITACCOUNTCONTROLLER_H_