/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/18 15:12:19

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
#include "pch.h"
#include "../include/MongoClient.h"
#include <sstream>
#include "StringUtil.h"
#include <iostream>
#include <mongocxx/exception/bulk_write_exception.hpp>

// ����һ�����ʼ��ϵĺ궨��
#define MONGO_COLLECTION_ACCESS(__CN__, __VAR__) \
if (!initPool()) return {}; \
auto client = m_pool->acquire(); \
auto __VAR__ = client->database(m_db); 

bool MongoClient::initPool()
{
	// �ж��Ƿ��Ѿ���ʼ��
	if (isInit) return true;
	// �����ʼ������ȫ����
	if (m_username == "")
	{
		cerr << "db connection info error" << endl;
		return false;
	}
	// ��ʼ�����ӳ�
	stringstream ss;
	ss << "mongodb://";
	ss << m_username << ":" << m_password;
	ss << "@" << m_host << ":" << m_port << "/" << m_db;
	ss << "?minPoolSize=" << m_min << "&maxPoolSize=" << m_max;
	mongocxx::uri uri{ ss.str().c_str() };
	m_pool = std::make_shared<mongocxx::pool>(uri);
	isInit = true;
	return true;
}

MongoClient::MongoClient(const string& username, const string& password, const string& host, const string& db, const string& port /*= "27017"*/)
{
	this->m_username = username;
	this->m_password = password;
	this->m_host = host;
	this->m_port = port;
	this->m_db = db;
	this->isInit = false;
}

MongoClient::MongoClient(const string& uri)
{
	if (uri != "") {
		std::vector<string> all = StringUtil::split(uri, ":");
		m_username = all[1];
		StringUtil::replace(&m_username, "/", "");
		std::vector<string> temp = StringUtil::split(all[2], "@");
		m_password = temp[0];
		m_host = temp[1];
		temp = StringUtil::split(all[3], "/");
		m_port = temp[0];
		m_db = temp[1];
	}
	this->isInit = false;
}

void MongoClient::setMax(int max)
{
	this->m_max = max;
}

void MongoClient::setMin(int min)
{
	this->m_min = min;
}

bool MongoClient::execute(const string& collectionName, std::function<void(mongocxx::collection*)> callfun)
{
	// ���ʼ���
	MONGO_COLLECTION_ACCESS(collectionName, db);
	mongocxx::collection collection = db[collectionName];
	// ��к���
	try
	{
		callfun(&collection);
		return true;
	}
	catch (const mongocxx::exception& e1)
	{
		cerr << e1.what() << endl;
	}
	catch (const std::exception& e2)
	{
		cerr << e2.what() << endl;
	}
	return false;
}

bsoncxx::types::bson_value::view MongoClient::addOne(const string& collectionName, const bsoncxx::document::view& document)
{
	// ���ʼ���
	MONGO_COLLECTION_ACCESS(collectionName, db);
	mongocxx::collection collection = db[collectionName];
	// ִ����Ӳ����ز���ID
	try
	{
		return collection.insert_one(document)->inserted_id();
	}
	catch (const mongocxx::bulk_write_exception& e1)
	{
		cerr << e1.what() << endl;
	}
	catch (const std::exception& e2)
	{
		cerr << e2.what() << endl;
	}
	return {};
}

int32_t MongoClient::addMultiple(const string& collectionName, const std::vector<bsoncxx::document::value>& documents)
{
	// ���ʼ���
	MONGO_COLLECTION_ACCESS(collectionName, db);
	mongocxx::collection collection = db[collectionName];
	// ִ�����
	try
	{
		return collection.insert_many(documents)->inserted_count();
	}
	catch (const mongocxx::bulk_write_exception& e1)
	{
		cerr << e1.what() << endl;
	}
	catch (const std::exception& e2)
	{
		cerr << e2.what() << endl;
	}
	return 0;
}
