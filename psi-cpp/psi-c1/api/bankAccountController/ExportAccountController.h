#pragma once

#ifndef _EXPORTACCOUNTCONTROLLER_H_
#define _EXPORTACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "domain/query/BankAccountQuery/ExportAccountQuery.h"
#include "api/ApiHelper.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/14 19:07:31
*/
class ExportAccountController
{
public:
	CREATE_API_FUN_QUERY(exportAccountExecl, execExportAccountExecl, ExportAccountQuery);
private:
	JsonVO<std::string> execExportAccountExecl(const ExportAccountQuery& query);
};

#endif // _EXPORTACCOUNTCONTROLLER_H_