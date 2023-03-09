#ifndef _BANKACCOUNTLIST_VO_
#define _BANKACCOUNTLIST_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/14  0.27
 * 银行账户列表
 */

class BankAccountListVO
{
	//先写目前这个列表能看到的
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
	//id
	CC_SYNTHESIZE(string, id, Id);

	//这些是列表里看不到的
	
	//attachment
	CC_SYNTHESIZE(string, attachment, Attachment);
	//createBy
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//currency
	CC_SYNTHESIZE(string, currency, Currency);
	//initBal
	CC_SYNTHESIZE(string, initBal, InitBal);
	//isEnabled
	CC_SYNTHESIZE(string, isEnabled, IsEnabled);
	//manager
	CC_SYNTHESIZE(string, manager, Manager);
	//version
	CC_SYNTHESIZE(string, version, Version);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(BankAccountListVO, updateBy, updateTime, accountNo, bankAddress, bankNo, createBy_dictText, createTime, currency_dictText, isEnabled_dictText, manager_dictText, name, remark);
	/*
	BIND_TO_JSON(BankAccountListVO, accountNo, bankAddress, bankNo, createBy_dictText, createTime, currency_dictText, isEnabled_dictText, manager_dictText, name, remark, id, attachment, createBy, currency, initBalisEnabled, manager, updateBy, updateTime, version);
	*/
};

#endif //_BANKACCOUNTLIST_VO_