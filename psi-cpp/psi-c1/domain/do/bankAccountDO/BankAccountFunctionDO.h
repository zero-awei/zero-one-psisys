#pragma once
#include "../DoInclude.h"
#ifndef _BANKACCOUNTDO_H_
#define _BANKACCOUNTDO_H_

/*
* 账户添加、修改
* @Author: Oxygen
* @Date: 2023/2/22 12:59:24
*/
class BankAccountFunctionDO
{
	// 账号
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	// 账户名
	CC_SYNTHESIZE(string, name, Name);
	// 币种
	CC_SYNTHESIZE(string, currency, Currency);
	// 行号
	CC_SYNTHESIZE(string, bankNo, BankNo);
	// 银行地址
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	// 账户管理员
	CC_SYNTHESIZE(string, manager, Manager);
	// 是否启用
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建者
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改者
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	BankAccountFunctionDO() {
		accountNo = "1234";
		name = "张三";
		currency = "人民币";
		bankNo = "23.12";
		bankAddress = "阿伟路996号";
		manager = "李业武";
		isEnabled = 1;
		remark = "无";
		createBy = "李业武";
		createTime = "2022.2.22";
		updateBy = "李业武";
		updateTime = "2022.2.22";
	}
};

#endif // _BANKACCOUNTDO_H_