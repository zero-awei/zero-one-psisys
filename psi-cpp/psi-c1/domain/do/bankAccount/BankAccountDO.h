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
	//id
	CC_SYNTHESIZE(string, id, Id);
	// 账号
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	//账户名
	CC_SYNTHESIZE(string, name, Name);
	// 币种
	CC_SYNTHESIZE(string, currency_dictText, Currency_dictText);
	//行号
	CC_SYNTHESIZE(string, bankNo, BankNo);
	// 银行地址
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	//账户管理员
	CC_SYNTHESIZE(string, manager_dictText, Manager_dictText);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//启用
	CC_SYNTHESIZE(int, isEnabled_dictText, IsEnabled_dictText);
	//创建人
	CC_SYNTHESIZE(string, createBy_dictText, CreateBy_dictText);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	BankAccountDO() {
		//id = "";
		accountNo = "";
		name = "";
		currency_dictText = "";
		bankNo = "";
		bankAddress = "";
		manager_dictText = "";
		remark = "";
		isEnabled_dictText = 1;
		createBy_dictText = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_BANKACCOUNT_DO_
