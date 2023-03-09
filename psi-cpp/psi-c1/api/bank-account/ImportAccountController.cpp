#include "stdafx.h"
#include "ImportAccountController.h"
#include "service/bank-account/ImportAccountService.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/14 22:12:22
*/
JsonVO<bool> ImportAccountController::execModifyAccountInfo(const FileDTO& dto)
{
	JsonVO<bool> res;
	ImportAccountService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		res.success(id);
	}
	else
	{
		res.fail(id);
	}
	return res;
}
