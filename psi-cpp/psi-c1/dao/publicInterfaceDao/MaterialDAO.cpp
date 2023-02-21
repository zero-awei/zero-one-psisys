#include "stdafx.h"
#include "MaterialDAO.h"
#include "MaterialMapper.h"

#define MATERIAL_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND bas_material.name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getCode().empty()) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
} \
if (obj.getType().empty()) { \
	sql << " AND bas_material_category.name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getType()); \
}\
if (obj.getTaxCode().empty()) { \
	sql << " AND bas_material_category.name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getTaxCode()); \
}\

std::list<MaterialReturnDO> MaterialDAO::selecMaterialWithPage(const MaterialQueryDO & obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT bas_material.id,bas_masterial.code,bas_masterial.name";
	sql << ",aux_name,category_id,bas_material_category.name";
	sql << ",model,unit_id,sale_price,tax_code,is_enabled,remark";
	sql << ",create_time,create_by,update_time,update_by";
	sql << "FROM bas_material, bas_material_category";
	MATERIAL_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MaterialMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialReturnDO, MaterialMapper>(sqlStr, mapper, params);
}

uint64_t MaterialDAO::count(const MaterialQueryDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_material,bas_material_category";
	MATERIAL_TERAM_PARSE(iObj, sql);
	sql << " AND bas_material.category_id=bas_material_category.id";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
