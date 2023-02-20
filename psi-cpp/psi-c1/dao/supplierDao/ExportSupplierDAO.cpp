#include "stdafx.h"
#include "ExportSupplierDAO.h"
#include "ExportSupplierMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getCode().empty()) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
} \
if (!obj.getName().empty()) { \
	sql << " AND name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} 

list<ExportSupplierDO> ExportSupplierDAO::selectSupplier(const ExportSupplierDO& obj)
{
	stringstream sql;
	sql << "SELECT * FROM bas_supplier";
	SAMPLE_TERAM_PARSE(obj, sql);
	ExportSupplierMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExportSupplierDO, ExportSupplierMapper>(sqlStr, mapper, params);
}
