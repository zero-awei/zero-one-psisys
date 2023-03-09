/*
author: qiuqiu
date:2023/2/19
*/


#include "stdafx.h"
#include "MaterialTypeDAO.h"
#include "MaterialTypeMapper.h"
#include <sstream>


list<MaterialTypeDO> MaterialTypeDAO::SelectMaterialType()
{
	stringstream sql;
	sql << "SELECT * FROM bas_material_category";
	string sqlStr = sql.str();
	MaterialTypeMapper mapper;
	return sqlSession->executeQuery<MaterialTypeDO, MaterialTypeMapper>(sqlStr, mapper);
}
