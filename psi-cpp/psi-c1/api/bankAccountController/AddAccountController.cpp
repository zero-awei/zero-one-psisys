#include "stdafx.h"
#include "AddAccountController.h"
#include "domain/service/bankAccountService/AddAccountService.h"

/*
* 账户添加
* @Author: Oxygen
* @Date: 2023/2/13 21:27:42
*/
JsonVO<uint64_t> AddAccountController::execAddBankAccount(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	JsonVO<uint64_t> result;
	AddAccountService service;
	//执行数据新增
	uint64_t id = service.saveData(dto, pdto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//响应结果
	return result;
}
