/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "MaterialClassificationDAO.h"
#include "MaterialClassificationMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define MATERIALCLASSIFICATION_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getCode().empty()) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
} 


//統計數據庫数据项的個數
uint64_t MaterialClassificationDAO::count(const MaterialClassificationDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(id) FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//分页查找 #需要名称和编码
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectWithPage(const MaterialClassificationDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, params);
}

//按姓名查找 
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByName(const string& name)
{
	string sql = "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category WHERE `name` LIKE CONCAT('%',?,'%')";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", name);
}

//按编码查询
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByCode(const string& code)
{
	string sql = "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category WHERE `code` LIKE CONCAT('%',?,'%')";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", code);
}

//按父节点查询 #用来找子级
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByPid(const string& pid)
{
	string sql = "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category WHERE `pid` LIKE CONCAT('%',?,'%')";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", pid);
}



//插入数据 #时间用string，这个返回值好像返回的是id，但是数据库中的id是varchar
uint64_t MaterialClassificationDAO::insert(const MaterialClassificationDO& iObj)
{
	string sql = "INSERT INTO `bas_material_category` (`id`,`pid`, `name`,`code`,`fullname`,`is_enabled`,`create_time`,`create_by`,`update_time`,`update_by`) VALUES (?, 0, ?, ?, ?, ?, ?, ?, ?. ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%i", iObj.getId(), iObj.getPid(), iObj.getName(), iObj.getCode(), iObj.getFullname(),iObj.getIsEnabled());
}

//修改数据 #同上 返回的是行数
int MaterialClassificationDAO::update(const MaterialClassificationDO& uObj)
{
	string sql = "UPDATE `bas_material_category` SET `name`= ?,`code`= ?,`fullname`= ?,`is_enabled`= ?,`create_time`= ?,`create_by`= ?,`update_time`= ?,`update_by` = ? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getName(), uObj.getCode(), uObj.getFullname(), uObj.getId());
}

//通过id删除数据 #删除数据后，如果是某个父类是否应该把子类一并删除；如果是子类应该要同时修改对应父类的has_child

//如果要同时删除子类，则可以删除pid=id的数据；如果是修改父类，可以用count统计pid=id的个数
int MaterialClassificationDAO::deleteById(string id)
{
	string sql = "DELETE FROM `bas_material_category` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}