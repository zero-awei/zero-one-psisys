#pragma once
#include <string>
#include "../../do/bankAccountDO/ExportAccountDO.h"
#include "../../vo/JsonVO.h"
#include "../../query/bankAccountQuery/ExportAccountQuery.h"
#include "../../dto/IDDTO.h"
#ifndef _BANKACCOUNTSERVICE_H_
#define _BANKACCOUNTSERVICE_H_

/*
* 银行账户导出
* @Author: Oxygen
* @Date: 2023/2/22 10:47:18
*/
class ExportAccountService
{
public:
	// 银行账户导出功能
	JsonVO<std::string> listAll(const StringIDs& query);
};

#endif // _BANKACCOUNTSERVICE_H_