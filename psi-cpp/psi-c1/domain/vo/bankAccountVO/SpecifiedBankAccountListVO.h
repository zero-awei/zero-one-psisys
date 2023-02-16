#pragma once
#ifndef _SPECIFIEDBANKACCOUNTLISTVO_H_
#define _SPECIFIEDBANKACCOUNTLISTVO_H_

#include"../../GlobalInclude.h"

class SpecifiedBankAccountListVO {
	CC_SYNTHESIZE(std::string, accountNo, AccountNo);
	CC_SYNTHESIZE(std::string, attachment,Attachment);
	CC_SYNTHESIZE(std::string, bankAddress, BankAddress);
	CC_SYNTHESIZE(std::string, bankNo,BankNo);
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	CC_SYNTHESIZE(std::string, createBy_dictText, CreateBy_dictText);
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	CC_SYNTHESIZE(std::string, currency, Currency); 
	CC_SYNTHESIZE(std::string, currency_dictText, Currency_dictText);
	CC_SYNTHESIZE(std::string, id, Id);
	CC_SYNTHESIZE(int, initBal, InitBal);
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	CC_SYNTHESIZE(std::string, isEnabled_dictText, IsEnabled_dictText);
	CC_SYNTHESIZE(std::string, manager, Manager);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, remark, Remark);
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	CC_SYNTHESIZE(std::string, version, Version);

public:
	BIND_TO_JSON(SpecifiedBankAccountListVO, accountNo, attachment, bankAddress, bankNo, createBy, createBy_dictText, createTime, currency, currency_dictText, id, initBal, isEnabled, isEnabled_dictText,
		manager, name, remark, updateBy, updateTime, version);
	SpecifiedBankAccountListVO() {
		accountNo = "11111";
		attachment = "";
		bankAddress = "";
		bankNo = "";
		createBy = "psi";
		createBy_dictText = u8"管理员";
		createTime = "2023-01-14 00:46:24";
		currency = "CNY";
		currency_dictText = u8"人民币";
		id = "1625174558616363009";
		initBal = 0;
		isEnabled = 1;
		isEnabled_dictText = u8"是";
		manager = "";
		name = "123";
		remark = "";
		updateBy = "";
		updateTime = "";
		version = "";

	}
};


#endif