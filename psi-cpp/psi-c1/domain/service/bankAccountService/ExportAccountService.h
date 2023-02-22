#pragma once
#include <string>
#include "../../query/bankAccountQuery/SpecifiedBankAccountQuery.h"
#include "../../do/bankAccountDO/ExportAccountDO.h"
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
	list<ExportAccountDO> listAll(const SpecifiedBankAccountQuery& query);
};

#endif // _BANKACCOUNTSERVICE_H_