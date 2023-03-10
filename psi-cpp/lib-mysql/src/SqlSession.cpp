/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:11:29
 
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
#include "../include/SqlSession.h"
#include <sstream>

void SqlSession::releasePreparedStatement()
{
	RELEASE_SQL_OBJECT(pstmt, "releasePreparedStatement");
}

void SqlSession::releaseStatement()
{
	RELEASE_SQL_OBJECT(stmt, "releaseStatement");
}

void SqlSession::releaseResultSet()
{
	RELEASE_SQL_OBJECT(res, "releaseResultSet");
}

int SqlSession::update(const string& sql, const char* fmt, va_list args)
{
	try
	{
		//1 获取prepareStatement对象
		pstmt = conn->prepareStatement(sql);
		//2 处理参数
		std::string curr(fmt);
		SQL_ARG_EXEC_1(pstmt, curr, args);
		//3 执行数据操作
		int row = pstmt->executeUpdate();
		//4 释放State
		releasePreparedStatement();
		return row;
	}
	catch (const std::exception& e)
	{
		//4 释放State
		releasePreparedStatement();
		printf("ExecuteUpdate Exception. %s\n", e.what());
	}
	return 0;
}

SqlSession::SqlSession()
{
	this->conn = DbInit::getConnPool()->GetConnection();
	this->pstmt = NULL;
	this->stmt = NULL;
	this->res = NULL;
	//设置编码
	this->setCharset("utf8");
}

SqlSession::~SqlSession()
{
	//析构释放连接对象
	DbInit::getConnPool()->ReleaseConnection(conn);
}

bool SqlSession::execute(const string& sql)
{
	bool result = false;
	TryFinally(
		[&] {
			stmt = conn->createStatement();
			result = stmt->execute(sql);
		},
		[](const std::exception e) {
			printf("Execute Exception. %s\n", e.what());
		},
		[=] {
			releaseStatement();
		}
		);
	return result;
}

int SqlSession::executeUpdate(const string& sql, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int row = update(sql, fmt, args);
	va_end(args);
	return row;
}

int SqlSession::executeUpdate(const string& sql)
{
	return executeUpdate(sql, "");
}

int SqlSession::executeUpdate(const string& sql, const SqlParams& params)
{
	try
	{
		//1 获取prepareStatement对象
		pstmt = conn->prepareStatement(sql);
		//2 处理参数
		SQL_ARG_EXEC_3(params, pstmt);
		//3 执行数据操作
		int row = pstmt->executeUpdate();
		//4 释放State
		releasePreparedStatement();
		return row;
	}
	catch (const std::exception& e)
	{
		//4 释放State
		releasePreparedStatement();
		printf("ExecuteUpdate Exception. %s\n", e.what());
	}
	return 0;
}

uint64_t SqlSession::executeInsert(const string& sql, const char* fmt, ...)
{
	//执行数据插入
	va_list args;
	va_start(args, fmt);
	int row = update(sql, fmt, args);
	va_end(args);

	//获取主键ID
	uint64_t id = 0;
	if (row == 1)
	{
		TryFinally(
			[&] {
				stmt = conn->createStatement();
				stmt->execute("SELECT LAST_INSERT_ID()");
				res = stmt->getResultSet();
				if (res->next()) {
					id = res->getInt64(1);
				}
			},
			[](std::exception e) {
				printf("Get Insert Id Exception. %s\n", e.what());
			},
			[=] {
				releaseResultSet();
				releaseStatement();
			}
		);
	}
	return id;
}

uint64_t SqlSession::executeInsert(const string& sql)
{
	return executeInsert(sql, "");
}

uint64_t SqlSession::executeInsert(const string& sql, const SqlParams& params)
{
	//执行数据插入
	int row = executeUpdate(sql, params);

	//获取主键ID
	uint64_t id = 0;
	if (row == 1)
	{
		TryFinally(
			[&] {
				stmt = conn->createStatement();
				stmt->execute("SELECT LAST_INSERT_ID()");
				res = stmt->getResultSet();
				if (res->next()) {
					id = res->getInt64(1);
				}
			},
			[](std::exception e) {
				printf("Get Insert Id Exception. %s\n", e.what());
			},
				[=] {
				releaseResultSet();
				releaseStatement();
			}
			);
	}
	return id;
}

uint64_t SqlSession::executeQueryNumerical(const string& sql, const char* fmt, ...)
{
	uint64_t result = 0;
	try
	{
		//1 获取prepareStatement对象
		pstmt = conn->prepareStatement(sql);
		//2 处理参数
		SQL_ARG_EXEC_2(pstmt, fmt);
		//3 执行查询
		res = pstmt->executeQuery();
		//4 处理查询结果
		if (res->next()) {
			result = res->getUInt64(1);
		}
		//5 释放资源
		releaseResultSet();
		releasePreparedStatement();
	}
	catch (const std::exception& e)
	{
		//5 释放资源
		releaseResultSet();
		releasePreparedStatement();
		printf("ExecuteQuery Exception. %s\n", e.what());
	}
	return result;
}

uint64_t SqlSession::executeQueryNumerical(const string& sql)
{
	return executeQueryNumerical(sql, "");
}

uint64_t SqlSession::executeQueryNumerical(const string& sql, const SqlParams& params)
{
	uint64_t result = 0;
	TryFinally(
		[&] {
			//1 获取prepareStatement对象
			pstmt = conn->prepareStatement(sql);
			//2 处理参数
			SQL_ARG_EXEC_3(params, pstmt);
			//3 执行查询
			res = pstmt->executeQuery();
			//4 处理查询结果
			if (res->next()) {
				result = res->getUInt64(1);
				/*我的理解是，因为 res = pstmt->executeQuery();是拿到了查询的结果嘛，也就是符合查询条件的供应商，
				然后if (res->next()) {result = res->getUInt64(1);}人意思就是判断查询到的结果是否为空，如果不为空就用查询到的数据来计算数据条数*/
			}
		},
		[](std::exception e) {
			printf("ExecuteQuery Exception. %s\n", e.what());
		},
		[=] {
			//4 释放资源
			releaseResultSet();//用于释放上面定义的res
			releasePreparedStatement();
		}
	);
	return result;
}

bool SqlSession::setCharset(const std::string& charset)
{
	stringstream ss;
	ss << "set names '" << charset << "'";
	string sql = ss.str();
	return this->execute(sql);
}

void SqlSession::beginTransaction()
{
	conn->setAutoCommit(false);
}

void SqlSession::commitTransaction()
{
	TryFinally(
		[=] {
			conn->commit();
		},
		[](const std::exception e) {
			printf("Commit Exception. %s\n", e.what());
		},
		[=] {
			conn->setAutoCommit(true);
		}
	);
}

void SqlSession::rollbackTransaction()
{
	TryFinally(
		[=] {
			conn->rollback();
		},
		[](const std::exception e) {
			printf("Rollback Exception. %s\n", e.what());
		},
		[=] {
			conn->setAutoCommit(true);
		}
	);
}
