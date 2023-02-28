#pragma once

#ifndef _EXPORTACCOUNTCONTROLLER_H_
#define _EXPORTACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/14 19:07:31
*/
class ExportAccountController
{
public:
	CREATE_API_FUN_JSON_PAYLOAD(exportAccountExecl, execExportAccountExecl, StringIDs);
private:
	JsonVO<std::string> execExportAccountExecl(const StringIDs& query, PayloadDTO payload);
};

#endif // _EXPORTACCOUNTCONTROLLER_H_