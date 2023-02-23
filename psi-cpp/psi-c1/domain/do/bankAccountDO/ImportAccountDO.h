#pragma once
#ifndef _IMPORTACCOUNTDO_H_
#define _IMPORTACCOUNTDO_H_
#include "../DoInclude.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:29:45
*/
class ImportAccountDO
{
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
	ImportAccountDO() {
		accountNo = "1";
		name = "1";
		currency = "人民币";
		init_bal = 23.00;
		bankNo = "23.12";
		bankAddress = "励志路996号";
		manager = "李业武";
		remark = "无";
		isEnabled = 1;
	}
};

#endif // _IMPORTACCOUNTDO_H_