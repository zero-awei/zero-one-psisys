#include "stdafx.h"
#include "EditAccountController.h"
#include "domain/service/bankAccountService/ModifyAccountService.h"
#include "domain/dto/bankAccountDTO/BankAccountDTO.h"

/*
* 账户信息修改
* @Author: Oxygen
* @Date: 2023/2/14 16:26:43
*/
JsonVO<std::string> EditAccountController::execModifyBankAccount(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	ModifyAccountService service;
	JsonVO<std::string> result;
	if (service.updateData(dto, pdto)) {
		result.success(dto.getAccountNo());
	}
	else
	{
		result.fail(dto.getAccountNo());
	}
	return result;
}
