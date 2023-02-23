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
if (!obj.getAccountNo().empty()) { \
	sql << " AND account_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getAccountNo()); \
} \
if (!obj.getName().empty()) { \
	sql << " AND name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getCurrency().empty()) { \
	sql << " AND currency=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCurrency()); \
} \
if (!obj.getInit_bal()) { \
	sql << " AND init_bal=?"; \
	SQLPARAMS_PUSH(params, "d", double, obj.getInit_bal()); \
} \
if (!obj.getBankNo().empty()) { \
	sql << " AND bank_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBankNo()); \
} \
if (!obj.getBankAddress().empty()) { \
	sql << " AND bank_address=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBankAddress()); \
} \
if (!obj.getManager().empty()) { \
	sql << " AND manager=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getManager()); \
} \
if (!obj.getRemark().empty()) { \
	sql << " AND remark=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getRemark()); \
} \
if (!obj.getIsEnabled()) { \
	sql << " AND is_enabled=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsEnabled()); \
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
