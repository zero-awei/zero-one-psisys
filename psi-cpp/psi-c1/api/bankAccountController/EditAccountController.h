#pragma once

#ifndef _EDITACCOUNTCONTROLLER_H_
#define _EDITACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/bankAccountDTO/BankAccountDTO.h"
#include "api/ApiHelper.h"

/*
* 账户信息修改
* @Author: Oxygen
* @Date: 2023/2/14 16:24:07
*/
class EditAccountController
{
public:
	CREATE_API_FUN_BODY(modifyBankAccount, execModifyBankAccount, BankAccountDTO);
private:
	JsonVO<uint64_t> execModifyBankAccount(const BankAccountDTO& dto);
};

#endif // _EDITACCOUNTCONTROLLER_H_