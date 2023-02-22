#include "stdafx.h"
#include "BankAccountDAO.h"

/*
* ÕË»§Ìí¼Ó
* @Author: Oxygen
* @Date: 2023/2/22 13:13:29
*/
uint64_t BankAccountDAO::insertAccount(const BankAccountDO& iObj)
{
	string sql = "INSERT INTO `bas_bank_account` (`account_no`, `name`, `currency`,`bank_no`,`bank_address`,`manager`,\
		`is_enabled`,`remark`,`create_by`) \
		VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%d%s%s", iObj.getAccountNo(), iObj.getName(), iObj.getCurrency(), \
		iObj.getBankNo(), iObj.getBankAddress(), iObj.getManager(), iObj.getIsEnabled(), iObj.getRemark(), \
		iObj.getCreateBy());
}

int BankAccountDAO::updateAccount(const BankAccountDO& uObj)
{
	string sql = "UPDATE `bas_bank_account` SET `name`=?, `currency`=?, `bank_no`=?, `bank_address`=?, `manager`=?,\
	`is_enabled`=?, `remark`=?, `update_by`=? WHERE `account_no`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%d%s%s%s", uObj.getName(), uObj.getCurrency(), \
		uObj.getBankNo(), uObj.getBankAddress(), uObj.getManager(), uObj.getIsEnabled(), uObj.getRemark(), \
		uObj.getUpdateBy(), uObj.getAccountNo());
}

int BankAccountDAO::deleteAccount(std::string id)
{
	string sql = "DELETE FROM `bas_bank_account` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
