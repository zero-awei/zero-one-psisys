/*
 Copyright Zero One Star. All rights reserved.

 @Author: zuichu
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
#include "PurQuotDAO.h"
#include "PurQuotMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getSex().empty()) { \
	sql << " AND bill_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
} \
if (obj.getAge() != -1) { \
	sql << " AND amt=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getAmt()); \
}
//
////计算总页数
//uint64_t PurQuotDAO::count(const PurQuotDO& iObj)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM pur_quot";
//	SAMPLE_TERAM_PARSE(iObj, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

////
//std::list<PurQuotDO> PurQuotDAO::selectWithPage(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize)
//{
//	stringstream sql;
//	sql << "SELECT * FROM pur_quot";
//	SAMPLE_TERAM_PARSE(obj, sql);
//	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
//	PurQuotMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<PurQuotDO, PurQuotMapper>(sqlStr, mapper, params);
//}
//
////查找指定账单号
//std::list<PurQuotDO> PurQuotDAO::selectByBill_no(const string& name)
//{
//	string sql = "SELECT * FROM pur_quot WHERE `name` LIKE CONCAT('%',?,'%')";
//	PurQuotMapper mapper;
//	return sqlSession->executeQuery<PurQuotDO, PurQuotMapper>(sql, mapper, "%s", name);
//}
//
////添加
//uint64_t PurQuotDAO::insertPurQuot(const PurQuotDO& iObj)
//{
//	string sql = "INSERT INTO ` pur_quot` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
//}
//
////修改状态
//int PurQuotDAO::updateStatus(const PurQuotDO& uObj)
//{
//	string sql = "UPDATE ` pur_quot` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
//}
//
////删除采购预付申请单号
//int PurQuotDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM ` pur_quot` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//}