#include "stdafx.h"
#include "ExportAccountController.h"
#include "service/bank-account/ExportAccountService.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/15 11:20:02
*/
JsonVO<std::string> ExportAccountController::execExportAccountExecl(const StringIDs& query, PayloadDTO payload)
{
	//返回下载地址
	ExportAccountService service;
	return service.listAll(query);
}