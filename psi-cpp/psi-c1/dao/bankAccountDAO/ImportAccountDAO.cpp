#include "stdafx.h"
#include "ImportAccountDAO.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:33:19
*/

uint64_t ImportAccountDAO::insert(const ImportAccountDO& iObj)
{
	string sql = "INSERT INTO `bas_bank_account` (`id`, `account_no`, `name`, `currency`, `init_bal`,\
	`bank_no`, `bank_address`, `manager`, `remark`, `is_enabled`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%d%s%s%s%s%i", iObj.getId(), iObj.getAccountNo(), iObj.getName(), iObj.getCurrency(), \
		iObj.getInit_bal(), iObj.getBankNo(), iObj.getBankAddress(), iObj.getManager(), iObj.getRemark(), iObj.getIsEnabled());
}
