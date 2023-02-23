#include "stdafx.h"
#include "BasWareHouseTreeDAO.h"
#include <sstream>
#include "./BasWareHouseTreeMapper.h"


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

uint64_t BasWareHouseTreeDAO::count(const BasWareHouseTreeDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_warehouse";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<BasWareHouseTreeDO> BasWareHouseTreeDAO::selectWithPage(const BasWareHouseTreeDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM bas_warehouse";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	BasWareHouseTreeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BasWareHouseTreeDO, BasWareHouseTreeMapper>(sqlStr, mapper, params);
}
