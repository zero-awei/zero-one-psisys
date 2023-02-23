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


#define MATERIALCLASSIFICATION_CODE_PARSE(code, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!(code=="")) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, code); \
} 

#define MATERIALCLASSIFICATION_NAME_PARSE(name, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!(name=="")) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, name); \
} \



//統計數據庫数据项的個數
uint64_t MaterialClassificationDAO::count(const MaterialClassificationDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(id) FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//分页查找 #需要名称或编码
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectWithPage(const MaterialClassificationDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, params);
}

//按名称查找 
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByName(const string& name)
{
	stringstream sql;
	sql << "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category";
	MATERIALCLASSIFICATION_NAME_PARSE(name, sql);
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, "%s", name);
}

//按编码查询
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByCode(const string& code)
{
	stringstream sql;
	sql << "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category";
	MATERIALCLASSIFICATION_CODE_PARSE(code, sql);
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, "%s", code);
}

//按父节点查询 #用来找子级
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByPid(const string& pid)
{
	string sql = "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category WHERE `pid` =?";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", pid);
}



//插入数据 #时间用string？
uint64_t MaterialClassificationDAO::insert(const MaterialClassificationDO& iObj)
{
	string sql = "INSERT INTO `bas_material_category` (`id`,`pid`,`has_child`,`code`,`name`,`fullname`,`is_enabled`,`create_by`,`update_by`,`version`) VALUES (?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%i%s%s%i", iObj.getId(),iObj.getPid(),iObj.getHasChild(),iObj.getCode(),iObj.getName(),iObj.getFullname(),iObj.getIsEnabled(), iObj.getCreateBy(), iObj.getUpdateBy(), iObj.getVersion());
}

//修改数据 
int MaterialClassificationDAO::update(const MaterialClassificationDO& iObj)
{
	string sql = "UPDATE `bas_material_category` SET `name`= ?,`code`=?,`fullname`=?,`is_enabled`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s", iObj.getName(), iObj.getCode(), iObj.getFullname(),iObj.getIsEnabled(),iObj.getId());
}
//通过id删除数据 #删除数据后，如果是某个父类是否应该把子类一并删除；如果是子类应该要同时修改对应父类的has_child

//如果要同时删除子类，则可以删除pid=id的数据；如果是修改父类，可以用count统计pid=id的个数
int MaterialClassificationDAO::deleteById(string id)
{
	string sql = "DELETE FROM `bas_material_category` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}