#pragma once

#ifndef _ACCOUNTCONTROLLER_H_
#define _ACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/BankAccountVO/AccountListVO.h"
#include "api/ApiHelper.h"
#include "domain/vo/PageVO.h"
#include "domain/query/BankAccount/AccountQuery.h"

/*
* 银行账户列表查询接口
* @Author: Oxygen
* @Date: 2023/2/12 14:02:09
*/
class AccountController
{
public:
	CREATE_API_FUN_QUERY3(queryAccountList, executeQueryAccountList);
private:
	JsonVO<PageVO<AccountListVO>> executeQueryAccountList(AccountQuery query);
};

#endif // _ACCOUNTCONTROLLER_H_