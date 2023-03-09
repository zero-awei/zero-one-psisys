#pragma once
#ifndef _BANKACCOUNTSERVICE_H_
#define _BANKACCOUNTSERVICE_H_
#include <string>
#include "../../domain/do/bank-account/ExportAccountDO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/bank-account/ExportAccountQuery.h"
#include "../../domain/dto/IDDTO.h"

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