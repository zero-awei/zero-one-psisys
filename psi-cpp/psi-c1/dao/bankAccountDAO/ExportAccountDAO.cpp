#include "stdafx.h"
#include "ExportAccountDAO.h"
#include "ExportAccountMapper.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/22 10:54:45
*/

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getAccount_no().empty()) { \
	sql << " AND account_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getAccount_no()); \
} \
if (!obj.getName().empty()) { \
	sql << " AND name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} 

std::list<ExportAccountDO> ExportAccountDAO::selectAccount(const ExportAccountDO& obj)
{
	stringstream sql;
	sql << "SELECT account_no, name FROM bas_bank_account";
	SAMPLE_TERAM_PARSE(obj, sql);
	ExportAccountMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExportAccountDO, ExportAccountMapper>(sqlStr, mapper, params);
}
