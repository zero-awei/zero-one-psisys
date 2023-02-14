#pragma once

#ifndef _EXPORTACCOUNTCONTROLLER_H_
#define _EXPORTACCOUNTCONTROLLER_H_
#include "domain/vo/JsonVO.h"
#include "domain/dto/BankAccountVO/BankAccountDTO.h"
#include "api/ApiHelper.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/14 19:07:31
*/
class ExportAccountController
{
public:
	CREATE_API_FUN_QUERY3(queryAccountExcel, execQueryAccount, BankAccountDTO);
private:
	JsonVO<std::string> execQueryAccountExcel(const SampleQuery& query, const FileDTO& fd);
};

#endif // _EXPORTACCOUNTCONTROLLER_H_