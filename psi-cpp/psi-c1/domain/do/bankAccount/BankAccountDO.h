#pragma once
/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * 接口：银行账户普通查询
 */

#ifndef _BANKACCOUNT_DO_
#define _BANKACCOUNT_DO_
#include "../DoInclude.h"

class BankAccountDO
{
	// 账号
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	// 银行地址
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	//行号
	CC_SYNTHESIZE(string, bankNo, BankNo);
	//创建人
	CC_SYNTHESIZE(string, createBy_dictText, CreateBy_dictText);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 币种
	CC_SYNTHESIZE(string, currency_dictText, Currency_dictText);
	//启用
	CC_SYNTHESIZE(int, isEnabled_dictText, IsEnabled_dictText);
	//账户管理员
	CC_SYNTHESIZE(string, manager_dictText, Manager_dictText);
	//账户名
	CC_SYNTHESIZE(string, name, Name);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	BankAccountDO() {
		accountNo = "";
		bankAddress = "";
		bankNo = "";
		createBy_dictText = "";
		createTime = "";
		currency_dictText = "";
		isEnabled_dictText = 1;
		manager_dictText = "";
		name = "";
		remark = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_BANKACCOUNT_DO_
