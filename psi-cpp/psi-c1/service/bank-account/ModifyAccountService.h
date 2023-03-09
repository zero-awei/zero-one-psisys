#pragma once
#ifndef _MODIFYACCOUNTSERVICE_H_
#define _MODIFYACCOUNTSERVICE_H_
#include "../../domain/dto/bank-account/BankAccountDTO.h"

/*
* 账户信息修改
* @Author: Oxygen
* @Date: 2023/2/22 14:28:27
*/
class ModifyAccountService
{
public:
	// 修改数据
	bool updateData(const BankAccountDTO& dto, const PayloadDTO& pdto);
};

#endif // _MODIFYACCOUNTSERVICE_H_