#include "stdafx.h"
#include "DeleteAccountController.h"
#include "domain/service/bankAccountService/DeleteAccountService.h"
#include "domain/dto/IDDTO.h"

/*
* 账户管添加
* @Author: Oxygen
* @Date: 2023/2/14 16:39:40
*/
JsonVO<std::string> DeleteAccountController::execRemoveBankAccount(const StringID& id)
{
	DeleteAccountService service;
	JsonVO<std::string> result;
	//执行数据删除
	if (service.removeData(id.getId())) {
		result.success(id.getId());
	}
	else
	{
		result.fail(id.getId());
	}
	//响应结果
	return result;
}
