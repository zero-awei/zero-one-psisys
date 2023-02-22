#pragma once
#include "../arch-demo/Macros.h"
#include "../DoInclude.h"

#ifndef _EXPORTACCOUNTDO_H_
#define _EXPORTACCOUNTDO_H_

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/22 10:43:14
*/
class ExportAccountDO
{
	// 账号
	CC_SYNTHESIZE(string, account_no, Account_no);
	// 银行账户名称
	CC_SYNTHESIZE(string, name, Name);
public:
	ExportAccountDO() {
		account_no = "1";
		name = "1";
	}
};

#endif // _EXPORTACCOUNTDO_H_