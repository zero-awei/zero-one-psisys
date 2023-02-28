#include "stdafx.h"
#include "DeleteAccountService.h"
#include "../../dao/bankAccountDAO/BankAccountFunctionDAO.h"

/*
* ÕË»§É¾³ý
* @Author: Oxygen
* @Date: 2023/2/22 15:30:57
*/

bool DeleteAccountService::removeData(std::string id)
{
	BankAccountFunctionDAO dao;
	return dao.deleteAccount(id) == 1;
}
