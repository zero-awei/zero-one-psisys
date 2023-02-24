#include "stdafx.h"
#include "MaterialTypeTreeDAO.h"
#include "./MaterialTypeTreeMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getCode().empty()) { \
	sql << " AND `code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
} \
if (!obj.getName().empty()) {\
		sql << " AND name=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
}\

uint64_t MaterialTypeTreeDAO::count(const MaterialTypeTreeDO & iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_material_category";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<MaterialTypeTreeDO> MaterialTypeTreeDAO::selectWithPage(const MaterialTypeTreeDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM bas_material_category";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MaterialTypeTreeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialTypeTreeDO, MaterialTypeTreeMapper>(sqlStr, mapper, params);
}



