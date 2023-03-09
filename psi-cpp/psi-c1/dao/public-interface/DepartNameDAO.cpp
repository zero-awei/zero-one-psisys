#include "stdafx.h"
#include "DepartNameDAO.h"
#include "DepartNameMapper.h"


std::list<DepartReturnDO> DepartNameDAO::selectDepartName(const DepartQueryDO& obj)
{
	stringstream sql;
	DepartNameMapper mapper;
	SqlParams params;
	//如果obj里的查询条件为空返回所有公司列表
	if (obj.getDepartName().empty())
	{
		sql << "SELECT id,depart_name";
		sql << " FROM sys_depart";
		sql << " WHERE parent_id is NULL";
	}
	else
	{
		sql << "SELECT id,depart_name";
		sql << " FROM sys_depart";
		sql << " WHERE 1=1";
		sql << " AND parent_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, obj.getId());
	}
	std::string str(sql.str());
	return sqlSession->executeQuery<DepartReturnDO, DepartNameMapper>(str, mapper, params);
}
