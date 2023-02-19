/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/19 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "BasMaterialDAO.h"
#include "BasMaterialMapper.h"
#include <sstream>
#include <string>

//定义条件解析宏，减少重复代码
#define BASMATERIAL_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
} \
if (!obj.getCode().empty()) { \
	sql << " AND category_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCategoryId()); \
} \
if (obj.getCategoryId().empty()) { \
	sql << " AND code like ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
}\
if (obj.getCategoryId().empty()) { \
	sql << " AND name like ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
}


uint64_t BasMaterialDAO::count(const BasMaterialDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_material";
	BASMATERIAL_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//分页展示
std::list<BasMaterialDO> BasMaterialDAO::selectWithPage(const BasMaterialDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT `A.id`,`A.code`,`A.name`,`A.aux_name`,`A.is_enabled`,`A.model`,`A.sale_price`,`A.tax_code`,`A.remark`,`A.create_by`,`A.create_time`,`A.update_by`,`A.update_time`,`B.name`,`C.name` FROM bas_material A ,bas_material_category B, bas_unit C  Where (A.category_id = B.id and A.unit_id = C.id ) ";
	BASMATERIAL_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	BasMaterialMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BasMaterialDO, BasMaterialMapper>(sqlStr, mapper, params);
}

//名称，编码，分类分别查询,前端返回分类名称（name），通过name三表（unit，category，material）连接查询，返回具体列
////unit_id, category_id,id,都返回给前端
std::list<BasMaterialDO> BasMaterialDAO::selectByName(const string& name)
{
	
	string sql = "SELECT `A.id`,`A.code`,`A.name`,`A.aux_name`,`A.is_enabled`,`A.model`,`A.sale_price`,`A.tax_code`,`A.remark`,`A.create_by`,`A.create_time`,`A.update_by`,`A.update_time`,`A.category_id`,`B.name`,`A.unit_id`,`C.name` FROM bas_material A, bas_material_category B, bas_unit C  Where(A.category_id = B.id and A.unit_id = C.id and `A.name` LIKE CONCAT('%',?,'%')) ";
	BasMaterialMapper mapper;
	return sqlSession->executeQuery<BasMaterialDO, BasMaterialMapper>(sql, mapper, "%s", name);
}
std::list<BasMaterialDO> BasMaterialDAO::selectByCode(const string& code)
{
	string sql = "SELECT `A.id`,`A.code`,`A.name`,`A.aux_name`,`A.is_enabled`,`A.model`,`A.sale_price`,`A.tax_code`,`A.remark`,`A.create_by`,`A.create_time`,`A.update_by`,`A.update_time`,`A.category_id`,`B.name`,`A.unit_id`,`C.name` FROM bas_material A, bas_material_category B, bas_unit C  Where(A.category_id = B.id and A.unit_id = C.id and `A.code` LIKE CONCAT('%',?,'%')) ";

	/*string sql = "SELECT * FROM bas_material WHERE `code` LIKE CONCAT('%',?,'%')";*/
	BasMaterialMapper mapper;
	return sqlSession->executeQuery<BasMaterialDO, BasMaterialMapper>(sql, mapper, "%s", code);
}
std::list<BasMaterialDO> BasMaterialDAO::selectByCategoryId(const string& categoryId)
{
	/*string sql = "SELECT * FROM bas_material WHERE `category_id` = ? ";*/
	string sql = "SELECT `A.id`,`A.code`,`A.name`,`A.aux_name`,`A.is_enabled`,`A.model`,`A.sale_price`,`A.tax_code`,`A.remark`,`A.create_by`,`A.create_time`,`A.update_by`,`A.update_time`,`A.category_id`,`B.name`,`A.unit_id`,`C.name` FROM bas_material A, bas_material_category B, bas_unit C  Where(A.category_id = B.id and A.unit_id = C.id and `A.category_id` = ?) ";

	BasMaterialMapper mapper;
	return sqlSession->executeQuery<BasMaterialDO, BasMaterialMapper>(sql, mapper, "%s", categoryId);
}

//新增行，前端返回分类名称，单位名称，需要查分类，单位两张表，得出各自id，再写入物料表
//默认前端返回的是，unit_id,category_id，而不是name
uint64_t BasMaterialDAO::insert(const BasMaterialDO& iObj)
{
	////前端返回物料分类的name？通过name 查找 category_id??
	//string sql_category = "SELECT `id` FROM bas_material_category WHERE `id` = ? ";
	//BasMaterialMapper mapper;
	//list categoryID=sqlSession->executeQuery<BasMaterialDO, BasMaterialMapper>(sql_category, mapper, "%s", iObj.getCategoryId());
	////前端返回物料分类的name？通过name 查找 unit_id??
	//string sql_unit = "SELECT `id` FROM bas_unit WHERE `id` = ? ";
	//BasMaterialMapper mapper;
	//list unitID = sqlSession->executeQuery<BasMaterialDO, BasMaterialMapper>(sql_unit, mapper, "%s", iObj.getUnitId());
	////list和string怎么转换？？？？？？？

	string sql = "INSERT INTO `bas_material` (`category_id`, `code`, `name`, `aux_name`, `is_enabled`, `model`, `unit_id`, `sale_price`, `tax_code`, `remark`, `create_by`, `create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%i%s%s%i%s%s%s%s%s%s%s", iObj.getCategoryId(), iObj.getCode(), iObj.getName(), iObj.getAuxName(), iObj.getIsEnabled(), iObj.getModel(), iObj.getUnitId(), iObj.getSalePrice(), iObj.getTaxCode(), iObj.getRemark(), iObj.getCreateBy(), iObj.getCreateTime());
}

//更新行，与新增行，相同
int BasMaterialDAO::update(const BasMaterialDO& uObj)
{
	string sql = "UPDATE `sample` SET `category_id`=?, `code`=?, `name`=?, `aux_name`=?, `is_enabled`=?, `model`=?, `unit_id`=?, `sale_price`=?, `tax_code`=?, `remark`=?, `update_by`=?, `update_time`=?  WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%i%s%s%s%s%s%s%s", uObj.getCategoryId(), uObj.getCode(), uObj.getName(), uObj.getAuxName(), uObj.getIsEnabled(), uObj.getModel(), uObj.getUnitId(), uObj.getSalePrice(), uObj.getTaxCode(), uObj.getRemark(), uObj.getUpdateBy(), uObj.getUpdateTime(), uObj.getId());
}

//删除行,***通过id删除,页面中id隐含，不显示
int BasMaterialDAO::deleteById(string id)
{
	string sql = "DELETE FROM `bas_material` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}