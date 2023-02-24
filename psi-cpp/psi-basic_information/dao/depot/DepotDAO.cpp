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
#include "DepotDAO.h"
#include "DepotMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql, params) \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getCode().empty()) { \
	sql << " AND `code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
}

#define ONLY_FOR_KID(obj, sql, params) \
sql<<" WHERE 1=1"; \
sql << " AND `pid`=?"; \
SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \

uint64_t DepotDAO::count(const DepotDO& iObj)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT COUNT(*) FROM bas_warehouse";
	if (!iObj.getId().empty()) {
		ONLY_FOR_KID(iObj, sql, params);
	}
	else {
		SAMPLE_TERAM_PARSE(iObj, sql, params);
	}
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<DepotDO> DepotDAO::selectWithPage(const DepotDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	SqlParams params; 
	// * 没改
	sql << "SELECT * FROM bas_warehouse";
	SAMPLE_TERAM_PARSE(obj, sql, params);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	DepotMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DepotDO, DepotMapper>(sqlStr, mapper, params);
}

std::list<DepotDO> DepotDAO::selectKid(const DepotDO& obj)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT id, pid, has_child, code, name, aux_name, phone, is_enabled, remark, create_by, create_time, update_by, update_time, version FROM bas_warehouse";
	SAMPLE_TERAM_PARSE(obj, sql, params);
	DepotMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DepotDO, DepotMapper>(sqlStr, mapper, params);
}

int DepotDAO::insertDepot(const DepotDO& iObj)
{
	string sql = "INSERT INTO `bas_warehouse` (`id`, `pid`, `has_child`, `name`, `code`, `aux_name`, `phone`, `is_enabled`, `remark`) VALUES (?, ?, 0, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%i%s", iObj.getId(), iObj.getPid(), iObj.getName(), iObj.getCode(), iObj.getAuxName(), iObj.getPhone(), iObj.getStart(), iObj.getRemarks());
}

int DepotDAO::insertKidDepot(const DepotDO& iObj)
{
	string sqlInsert = "INSERT INTO `bas_warehouse` (`id`, `pid`, `has_child`, `name`, `code`, `aux_name`, `phone`, `is_enabled`, `remark`) VALUES (?, ?, 0, ?, ?, ?, ?, ?, ?)";
	string sqlUpdate = "UPDATE `bas_warehouse` SET `has_child`=? WHERE `pid`=?";
	return sqlSession->executeUpdate(sqlInsert, "%s%s%s%s%s%i%i%s", iObj.getId(), iObj.getPid(), iObj.getName(), iObj.getCode(), iObj.getAuxName(), iObj.getPhone(), iObj.getStart(), iObj.getRemarks())
		&& sqlSession->executeUpdate(sqlUpdate, "%s%s", "1", iObj.getPid());
}

int DepotDAO::deleteDepot(const DepotDO& iObj)
{
	string sql = "DELETE FROM `bas_warehouse` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", iObj.getId());
}

int DepotDAO::update(const DepotDO& uObj)
{
	// 缺了修改人和修改时间
	string sql = "UPDATE `bas_warehouse` SET `name`=?, `code`=?, `aux_name`=?, `phone`=?, `is_enabled`=?, `remark`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%i%s%s", uObj.getName(), uObj.getCode(), uObj.getAuxName(), uObj.getPhone(), uObj.getStart(), uObj.getRemarks(), uObj.getId());
}