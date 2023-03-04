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
#include "MeasurementDAO.h"
#include "MeasurementMapper.h"
#include <sstream>
#include <string>
#include <list>
using namespace std;

//定义条件解析宏，减少重复代码
#define Measurement_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getSymbol().empty()) { \
	sql << " AND `symbol`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSymbol()); \
} \
if (obj.getFactor() != -1) { \
	sql << " AND `factor`=?"; \
	SQLPARAMS_PUSH(params, "ul", uint64_t, obj.getFactor()); \
} \
if (obj.getIs_enabled().empty()) { \
	sql << " AND `is_enabled`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getIs_enabled()); \
}

#define MEASUREMENT_LIST_TERAM_PARSE(obj, sql) \
sql << " WHERE pid=0"; \
SqlParams params;\
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
}

//统计数据条数
uint64_t MeasurementDAO::count(const MeasurementDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_unit";
	MEASUREMENT_LIST_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//分页查询数据
list<MeasurementDO> MeasurementDAO::selectWithPage(const MeasurementDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT `id`,`name`,`symbol`,`has_child`,`factor`,`is_enabled`, `create_time`,`create_by`, `update_time`, `update_by` FROM bas_unit";
	MEASUREMENT_LIST_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MeasurementListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MeasurementDO, MeasurementListMapper>(sqlStr, mapper, params);
}

//查询指定单位的子级列表
list<MeasurementDO> MeasurementDAO::selectKidData(const string& id)
{
	stringstream sql;
	sql << "SELECT `id`, `name`, `symbol`, `has_child`, `factor`, `is_enabled`, `create_time`, `create_by`, `update_time`, `update_by` FROM bas_unit where `pid`=?";
	MeasurementListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MeasurementDO, MeasurementListMapper>(sqlStr, mapper, "%s", id);
}

//通过Id查询数据详细信息
list<MeasurementDO> MeasurementDAO::selectById(const string& id)
{
	string sql = "SELECT `id`, `name`, `symbol`, `has_child`, `pid`, `factor`, `is_enabled`, `create_time`, `create_by`, `update_time`, `update_by` FROM bas_unit WHERE `id`=?";
	MeasurementMapper mapper;
	return sqlSession->executeQuery<MeasurementDO, MeasurementMapper>(sql, mapper, "%s", id);
}

//通过pid查询数据
list<MeasurementDO> MeasurementDAO::selectByPid(const string& pid)
{
	string sql = "SELECT 'id'  FROM `bas_unit` WHERE `pid`=?";
	MeasurementPidMapper mapper;
	return sqlSession->executeQuery<MeasurementDO, MeasurementPidMapper>(sql, mapper, "%s", pid);
}

//通过名称查询数据详细信息
list<MeasurementDO> MeasurementDAO::selectByName(const string& name)
{
	string sql = "SELECT `id`, `name`, `symbol`, `has_child`, `pid`, `factor`, `is_enabled`, `create_time`, `create_by`, `update_time`, `update_by` FROM bas_unit WHERE `name`=?";
	MeasurementMapper mapper;
	return sqlSession->executeQuery<MeasurementDO, MeasurementMapper>(sql, mapper, "%s", name);
}

//新增数据
int MeasurementDAO::insert(const MeasurementDO& iObj)
{
	string sql = "INSERT INTO `bas_unit` (`id`, `name`, `symbol`, `has_child`, `pid`, `factor`, `is_enabled`, `create_time`, `create_by`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%d%i%s%s", iObj.getId(), iObj.getName(), iObj.getSymbol(), iObj.getHas_child(), iObj.getPid(), iObj.getFactor(), iObj.getIs_enabled(),
		iObj.getCreate_time(), iObj.getCreate_by());
}

//修改计量单位
int MeasurementDAO::update(const MeasurementDO& uObj)
{
	string sql = "UPDATE `bas_unit` SET `name`=?, `symbol`=?, `factor`=?, `is_enabled`=?, `update_time`=?, `update_by`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%d%i%s%s%s", uObj.getName(), uObj.getSymbol(), uObj.getFactor(), uObj.getIs_enabled(), uObj.getUpdate_time(), uObj.getUpdate_by(), uObj.getId());
}

//修改has_child
int MeasurementDAO::updateHas_child(const int& count, const string& id)
{
	string sql = "UPDATE `bas_unit` SET `has_child`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s", count, id);
}

//修改Pid
int MeasurementDAO::updatePid(const string& pid, const string& id)
{
	string sql = "UPDATE `bas_unit` SET `pid`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s", pid, id);
}

//通过ID删除数据
int MeasurementDAO::deleteById(const string& id)
{
	string sql = "DELETE FROM `bas_unit` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

//通过Pid删除数据
int MeasurementDAO::deleteByPid(const string& pid)
{
	string sql = "DELETE FROM `bas_unit` WHERE `pid`=?";
	return sqlSession->executeUpdate(sql, "%s", pid);
}

//文件导入
uint64_t MeasurementDAO::ImportFile(const MeasurementImportFileDO& iObj)
{
	if (iObj.getImport().empty()) return -1;

	uint64_t count = 0;
	for (auto it = iObj.getImport().begin(); it != iObj.getImport().end(); it++)
	{
		string sql = "INSERT INTO `bas_unit` (`id`, `name`, `symbol`, `has_child`, `pid`, `factor`, `is_enabled`, `create_time`, `create_by`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
		sqlSession->executeInsert(sql, "%s%s%s%i%s%d%i%s%s", (*it).getId(), (*it).getName(), (*it).getSymbol(), (*it).getHas_child(), (*it).getPid(), (*it).getFactor(), (*it).getIs_enabled(),
			(*it).getCreate_time(), (*it).getCreate_by());
		count++;
	}
	return count;
}

//文件导出查询
list<MeasurementDO> MeasurementDAO::selectExportFile(const string& id)
{
	MeasurementDAO dao;
	string sql = "SELECT `name`, `symbol`, `has_child`, `pid`, `factor`, `is_enabled` FROM `bas_unit` WHERE `id`=?";
	MeasurementImportMapper mapper;
	return sqlSession->executeQuery<MeasurementDO, MeasurementImportMapper>(sql, mapper, "%s", id);
}