#include "stdafx.h"
#include "DeliveryMethodTypeDAO.h"
#include "DeliveryMethodTypeMapper.h"

list<DeliveryMethodTypeDO> DeliveryMethodTypeDAO::SelectMaterialType(const string& num)
{
	string sql = "SELECT * FROM sys_dict_item WHERE `dict_id`=?";
	DeliveryMethodTypeMapper mapper;
	return sqlSession->executeQuery<DeliveryMethodTypeDO, DeliveryMethodTypeMapper>(sql, mapper, "%s", num);
}
