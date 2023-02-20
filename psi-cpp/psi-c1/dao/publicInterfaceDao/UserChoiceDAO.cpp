#include "stdafx.h"
#include "UserChoiceDAO.h"
#include "UserChoiceMapper.h"
#include <sstream>


std::list<UserChoiceReturnDO> UserChoiceDAO::selecUserWithPage(const UserChoiceQueryDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	//定义装填sql语句的string流
	stringstream sql;
	SqlParams params;
	sql << "SELECT sys_user.id,username,sex,phone,sys_depart.depart_name";
	sql << " FROM sys_user,sys_depart";
	sql << " WHERE 1=1";
	sql << " AND sys_user.depart_ids=sys_depart.id";
	sql << " AND sys_user.username=?";
	SQLPARAMS_PUSH(params, "s", std::string, obj.getUserName());
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	UserChoiceMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<UserChoiceReturnDO, UserChoiceMapper>(sqlStr, mapper, params);
}

uint64_t UserChoiceDAO::count(const UserChoiceQueryDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sys_user";
	sql << " WHERE 1=1 AND";
	sql << " username=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, iObj.getUserName());
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
