#pragma once
#ifndef _ADDACCOUNTSERVICE_H_
#define _ADDACCOUNTSERVICE_H_
#include <list>
#include "../../dto/bankAccountDTO/BankAccountDTO.h"

/*
* 账户添加
* @Author: Oxygen
* @Date: 2023/2/22 12:50:51
*/
class AddAccountService
{
public:
	// 保存数据
	int saveData(const BankAccountDTO& dto, const PayloadDTO& pdto);
};

#endif // _ADDACCOUNTSERVICE_H_