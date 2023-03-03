#include "stdafx.h"
#include "../../dao/publicInterfaceDAO/areaDAO.h"
#include "areaMapper.h"
#include <sstream>


//照着阿伟写的宏 解决代码重复的问题
#define AREA_TERAM_PARSE(obj, sql,typeStr) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getAreaName().empty()) { \
	sql << " AND `"+typeStr+"`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getAreaName()); \
} \


std::list<AreaReturnDO> AreaDAO::selectArea(const AreaQueryDO& obj)
{
	stringstream sql;
	sql << "SELECT ";
	sql << obj.getReturnTypeStr(); 
	sql << " FROM test_enhance_select";
	AreaMapper mapper;
	AREA_TERAM_PARSE(obj, sql, obj.getTypeStr());
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AreaReturnDO, AreaMapper>(sqlStr, mapper, params);
}
