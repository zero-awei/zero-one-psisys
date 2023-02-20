#include "stdafx.h"
#include "PurQuotDAO.h"
#include "PurQuotMapper.h"
#include <sstream>


#define PUR_QUOT_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getBill_date().empty()) { \
	sql << " AND bill_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
} \
if (obj.getSubject().empty()) { \
	sql << " AND subject=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
}

uint64_t PurQuotDAO::count(const PurQuotFindBillDO & iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_quot";
	PUR_QUOT_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
list<PurQuotFindBillDO> PurQuotDAO::selectPurQuotFindBillDO(const PurQuotFindBillDO& obj, uint64_t pageIndex, uint64_t pageSize) {
	stringstream sql;
	sql << "SELECT * FROM pur_quot";
	PUR_QUOT_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurQuotMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotFindBillDO, PurQuotMapper>(sqlStr, mapper, params);
}

