#include "stdafx.h"
#include "ExportAccountDAO.h"
#include "ExportAccountMapper.h"
#include <sstream>
/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/22 10:54:45
*/

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getId().empty()) { \
	sql << " AND id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
} 


std::list<ExportAccountDO> ExportAccountDAO::selectAccount(const ExportAccountDO& obj)
{
	stringstream sql;
	sql << "SELECT account_no, name, currency, init_bal, bank_no, bank_address,\
	manager, remark, is_enabled FROM bas_bank_account";
	SAMPLE_TERAM_PARSE(obj, sql);
	ExportAccountMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExportAccountDO, ExportAccountMapper>(sqlStr, mapper, params);
}

std::list<ExportAccountDO> ExportAccountDAO::selectAllAccount(const ExportAccountDO& obj)
{
	stringstream sql;
	sql << "SELECT account_no, name, currency, init_bal, bank_no, bank_address,\
	manager, remark, is_enabled FROM bas_bank_account";
	SAMPLE_TERAM_PARSE(obj, sql);
	ExportAccountMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExportAccountDO, ExportAccountMapper>(sqlStr, mapper, params);
}