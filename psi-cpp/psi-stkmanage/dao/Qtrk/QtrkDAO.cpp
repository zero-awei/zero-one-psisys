
#include "stdafx.h"
#include "QtrkDAO.h"
#include "QtrkMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define Qtrk_TERAM_PARSE(obj, sql) \
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

uint64_t SampleDAO::count(const SampleDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<SampleDO> SampleDAO::selectWithPage(const SampleDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	SampleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sqlStr, mapper, params);
}

std::list<SampleDO> SampleDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	SampleMapper mapper;
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sql, mapper, "%s", name);
}

uint64_t SampleDAO::insert(const SampleDO& iObj)
{
	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
}

int SampleDAO::update(const SampleDO& uObj)
{
	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}

int SampleDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}