#include "stdafx.h"
#include "BasBankAccountDAO.h"
#include<sstream>
#include"./BasBankAccountMapper.h"



list<BasBankAccountDO> BasBankAccountDAO::selectAccount()
{
	stringstream sql;
	sql << "SELECT id,account_no FROM bas_bank_account";
	string sqlStr = sql.str();
	BasBankAccountMapper mapper;
	return sqlSession->executeQuery<BasBankAccountDO, BasBankAccountMapper>(sqlStr, mapper);
}
