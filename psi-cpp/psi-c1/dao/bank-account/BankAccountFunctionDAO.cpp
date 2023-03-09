#include "stdafx.h"
#include "BankAccountFunctionDAO.h"

/*
* 账户添加、修改和删除
* @Author: Oxygen
* @Date: 2023/2/22 13:13:29
*/
int BankAccountFunctionDAO::insertAccount(const BankAccountFunctionDO& iObj, uint64_t ID)
{
	string id = to_string(ID);
	string sql = "INSERT INTO `bas_bank_account` (`id`, `account_no`, `name`, `currency`,`bank_no`,`bank_address`,`manager`,\
		`is_enabled`,`remark`,`create_by`) \
		VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s", id, iObj.getAccountNo(), iObj.getName(), iObj.getCurrency(), \
		iObj.getBankNo(), iObj.getBankAddress(), iObj.getManager(), iObj.getIsEnabled(), iObj.getRemark(), \
		iObj.getCreateBy());
}

int BankAccountFunctionDAO::updateAccount(const BankAccountFunctionDO& uObj)
{
	string sql = "UPDATE `bas_bank_account` SET `name`=?, `currency`=?, `bank_no`=?, `bank_address`=?, `manager`=?,\
	`is_enabled`=?, `remark`=?, `update_by`=? WHERE `account_no`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%s%s%s", uObj.getName(), uObj.getCurrency(), \
		uObj.getBankNo(), uObj.getBankAddress(), uObj.getManager(), uObj.getIsEnabled(), uObj.getRemark(), \
		uObj.getUpdateBy(), uObj.getAccountNo());
}

int BankAccountFunctionDAO::deleteAccount(std::string id)
{
	string sql = "DELETE FROM `bas_bank_account` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
