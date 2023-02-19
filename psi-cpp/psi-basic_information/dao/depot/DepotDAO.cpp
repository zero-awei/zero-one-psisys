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
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getCode().empty()) { \
	sql << " AND `code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
}

#define ONLY_FOR_KID(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getId().empty()) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
}

uint64_t DepotDAO::count(const DepotDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_warehouse";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<DepotDO> DepotDAO::selectWithPage(const DepotDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM bas_warehouse";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	DepotMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DepotDO, DepotMapper>(sqlStr, mapper, params);
}

uint64_t DepotDAO::countKid(const DepotDetailVO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_warehouse";
	ONLY_FOR_KID(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


std::tuple<std::string, std::string> DepotDAO::getKidNameAndCode(const DepotDetailVO& iObj)
{
	stringstream sql;
	sql << "SELECT NEXT FROM bas_warehouse";
	ONLY_FOR_KID_SEARCH(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}