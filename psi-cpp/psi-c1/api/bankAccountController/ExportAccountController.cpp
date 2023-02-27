#include "stdafx.h"
#include "ExportAccountController.h"
#include "domain/service/bankAccountService/ExportAccountService.h"
#include "nlohmann/json_fwd.hpp"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/15 11:20:02
*/
JsonVO<std::string> ExportAccountController::execExportAccountExecl(const list<ExportAccountQuery>& query, PayloadDTO payload)
{
	//返回下载地址
	ExportAccountService service;
	return service.listAll(query);
}