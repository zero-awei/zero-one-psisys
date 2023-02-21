#include "stdafx.h"
#include "CgthckDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1 AND `is_rubric` = 1"; \
if (!obj.getBillNo().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo()); \
} \
if (!obj.getBillDate().empty()) { \
	sql << " AND bill_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDate()); \
} \
if (!obj.getSupplierId().empty()) { \
	sql << " AND supplier_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSupplierId()); \
}

uint64_t CgthckDAO::count(const CgthckDO& iobj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM " << DATABASE;
	SAMPLE_TERAM_PARSE(iobj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<CgthckDO> CgthckDAO::selectById(const string& id)
{
	string sql{ "" };
	sql += "SELECT `bill_no`, `bill_date`, `supplier_id` FROM " + string{ DATABASE } + " WHERE `bill_no` LIKE CONCAT('%', ?, '%') AND `is_rubric` = 1";
	CgthckMapper mapper;
	return sqlSession->executeQuery<CgthckDO, CgthckMapper>(sql, mapper, "%s", id);
}

uint64_t CgthckDAO::insert(const CgthckDO& iobj)
{
	string sql{""};
	sql += "INSERT INTO " + string{ DATABASE } + " (`bill_no`, `bill_date`, `supplier_id`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s", iobj.getBillNo(), iobj.getBillDate(), iobj.getSupplierId());
}

int CgthckDAO::update(const CgthckDO& iobj)
{
	string sql{ "" };
	sql += "UPDATE " + string{ DATABASE } + " SET `bill_date`=?, `supplier_id`=? WHERE `bill_no`=?";
	return sqlSession->executeInsert(sql, "%s%s%s", iobj.getBillDate(), iobj.getSupplierId(), iobj.getBillNo());
}

int CgthckDAO::deleteById(const CgthckDO& iobj)
{
	return 0;
}
