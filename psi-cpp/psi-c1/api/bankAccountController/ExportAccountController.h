#pragma once

#ifndef _EXPORTACCOUNTCONTROLLER_H_
#define _EXPORTACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "api/ApiHelper.h"
#include "domain/query/bankAccountQuery/ExportAccountQuery.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/14 19:07:31
*/
class ExportAccountController
{
public:
	CREATE_API_FUN_BODY_PAYLOAD(exportAccountExecl, execExportAccountExecl, list<ExportAccountQuery>);
private:
	JsonVO<std::string> execExportAccountExecl(const list<ExportAccountQuery>& query, PayloadDTO payload);
};

#endif // _EXPORTACCOUNTCONTROLLER_H_