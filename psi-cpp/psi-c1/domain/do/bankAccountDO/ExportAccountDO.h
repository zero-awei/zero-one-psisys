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
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 账号
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	// 账户名
	CC_SYNTHESIZE(string, name, Name);
	// 币种
	CC_SYNTHESIZE(string, currency, Currency);
	// 初始余额
	CC_SYNTHESIZE(double, init_bal, Init_bal);
	// 行号
	CC_SYNTHESIZE(string, bankNo, BankNo);
	// 银行地址
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	// 账户管理员
	CC_SYNTHESIZE(string, manager, Manager);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否启用
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
public:
	ExportAccountDO() {
	}
};

#endif // _EXPORTACCOUNTDO_H_