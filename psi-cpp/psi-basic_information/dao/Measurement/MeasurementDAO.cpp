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

//定义条件解析宏，减少重复代码
#define Measurement_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getSex().empty()) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSex()); \
} \
if (obj.getAge() != -1) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getAge()); \
}

uint64_t MeasurementDAO::count(const MeasurementDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	Measurement_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<MeasurementDO> MeasurementDAO::selectWithPage(const MeasurementDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	Measurement_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MeasurementMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MeasurementDO, MeasuremnetMapper>(sqlStr, mapper, params);
}

std::list<MeasurementDO> MeasurementDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	MeasurementMapper mapper;
	return sqlSession->executeQuery<MeasurementDO, MeasurementMapper>(sql, mapper, "%s", name);
}

uint64_t MeasurementDAO::insert(const MeasurementDO& iObj)
{
	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
}

int MeasurementDAO::update(const MeasurementDO& uObj)
{
	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}

int MeasurementDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}