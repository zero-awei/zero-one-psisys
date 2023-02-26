#include "stdafx.h"
#include "ExportSupplierDAO.h"
#include "ExportSupplierMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getId().empty()) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
} 

list<ExportSupplierDO> ExportSupplierDAO::selectSupplier(const ExportSupplierDO& obj)
{
	stringstream sql;
	sql << "SELECT code, name, short_name, aux_name, supplier_category, supplier_level, is_enabled FROM bas_supplier";
	SAMPLE_TERAM_PARSE(obj, sql);
	ExportSupplierMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExportSupplierDO, ExportSupplierMapper>(sqlStr, mapper, params);
}
