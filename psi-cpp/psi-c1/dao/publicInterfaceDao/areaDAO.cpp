#include "stdafx.h"
#include "../../dao/publicInterfaceDAO/areaDAO.h"
#include "areaMapper.h"
#include <sstream>


#define AREA_TERAM_PARSE(obj, sql,conditon) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getAreaName().empty()) { \
	sql << " AND `"+conditon+"`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getAreaName()); \
} \
if (obj.getId()) { \
	sql << " AND id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, obj.getId()); \
} \



std::list<AreaDO> AreaDAO::selectArea(const AreaDO& obj)
{
	stringstream sql;
	string condition = obj.getName();
	sql << "SELECT "+condition+" FROM test_enhance_select";
	AREA_TERAM_PARSE(obj, sql,conditon);
	AreaMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AreaDO, AreaMapper>(sqlStr, mapper, params);
}
