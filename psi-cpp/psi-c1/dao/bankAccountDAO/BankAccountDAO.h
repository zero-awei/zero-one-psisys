#pragma once
#ifndef _BANKACCOUNTDAO_H_
#define _BANKACCOUNTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/bankAccountDO/BankAccountDO.h"

/*
* 账户添加
* @Author: Oxygen
* @Date: 2023/2/22 13:06:57
*/
class BankAccountDAO : public BaseDAO
{
public:
	// 插入数据
	int insertAccount(const BankAccountDO& iObj, uint64_t ID);
	// 修改数据
	int updateAccount(const BankAccountDO& uObj);
	// 通过ID删除数据
	int deleteAccount(std::string id);
};

#endif // _BANKACCOUNTDAO_H_