#pragma once

#ifndef _BANKACCOUNTDTO_H_
#define _BANKACCOUNTDTO_H_
#include "../../GlobalInclude.h"

/*
* 银行账户信息
* @Author: Oxygen
* @Date: 2023/2/13 21:13:11
*/
class BankAccountDTO
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
	CC_SYNTHESIZE(string, isEnabled, IsEnabled);
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
	// 绑定JSON转换方法
	friend void from_json(const json& j, BankAccountDTO& t); // NOLINT
	BIND_TO_JSON(BankAccountDTO, accountNo, name, currency, bankNo,
		bankAddress, manager, isEnabled, remark, createBy, createTime,
		updateBy, updateTime);
};

#endif // _BANKACCOUNTDTO_H_