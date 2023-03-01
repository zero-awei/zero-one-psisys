/*
 Copyright Zero One Star. All rights reserved.

 @Author: douhao
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
#include "CurrencyDAO.h"
#include "CurrencyMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CURRENCY_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
}\
if (!obj.getCode().empty()) { \
	sql << " AND `code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
}

uint64_t CurrencyDAO::count(const CurrencyDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_currency";
	CURRENCY_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CurrencyDO> CurrencyDAO::selectWithPage(const CurrencyDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM bas_currency";
	CURRENCY_TERAM_PARSE(obj, sql);
	if (pageIndex > 0 && pageSize > 0)
		sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	CurrencyMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CurrencyDO, CurrencyMapper>(sqlStr, mapper, params);
}

std::list<CurrencyDO> CurrencyDAO::selectByName(const string& name)
{ 
	string sql = "SELECT * FROM bas_currency WHERE `name`=?";
	CurrencyMapper mapper;
	return sqlSession->executeQuery<CurrencyDO, CurrencyMapper>(sql, mapper, "%s", name);
}

uint64_t CurrencyDAO::insert(const CurrencyDO& iObj)
{
	string sql = "INSERT INTO `bas_currency` (`id`, `code`, `name`,`is_functional`, `is_enabled`, `create_by`,\
					 `create_time`, `update_by`, `update_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%i%s%s%s%s", iObj.getId(), iObj.getCode(), iObj.getName(),\
		iObj.getIsFunctional(), iObj.getIsEnabled(), iObj.getCreateBy(), iObj.getCreateTime(), iObj.getUpdateBy(), iObj.getUpdateTime());

}

int CurrencyDAO::update(const CurrencyDO& uObj)
{
	string sql = "UPDATE `bas_currency` SET  `code`=?, `name`=?,`is_functional`=?, `is_enabled`=?, \
					  `update_by`=?, `update_time`=?  WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%i%s%s%s",  uObj.getCode(), uObj.getName(), uObj.getIsFunctional(),\
			uObj.getIsEnabled(), uObj.getUpdateBy(), uObj.getUpdateTime(),  uObj.getId());
}

int CurrencyDAO::deleteById(string code)
{
	string sql = "DELETE FROM `bas_currency` WHERE `code`=?";
	return sqlSession->executeUpdate(sql, "%s", code);
}