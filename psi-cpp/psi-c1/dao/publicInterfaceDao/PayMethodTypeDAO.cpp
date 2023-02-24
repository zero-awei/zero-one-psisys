#include "stdafx.h"
#include "PayMethodTypeDAO.h"
#include "PayMethodTypeMapper.h"

list<PayMethodTypeDO> PayMethodTypeDAO::SelectMaterialType(const string& str)
{

	string sql = "SELECT * FROM sys_dict_item WHERE `dict_id`=?";
	PayMethodTypeMapper mapper;
	return sqlSession->executeQuery<PayMethodTypeDO, PayMethodTypeMapper>(sql, mapper, "%s",str);

}
