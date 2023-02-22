#include "stdafx.h"
#include "CgthckDAO.h"
#include <sstream>

// 测试中

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
	sql << "SELECT COUNT(*) FROM " << DATABASE1;
	SAMPLE_TERAM_PARSE(iobj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<CgthckDO> CgthckDAO::selectById(const string& id)
{
	string sql = "SELECT `bill_no`, `bill_date`, `supplier_id` FROM " + string{ DATABASE1 } + " WHERE `bill_no` LIKE CONCAT('%', ?, '%') AND `is_rubric` = 1";
	CgthckMapper mapper;
	return sqlSession->executeQuery<CgthckDO, CgthckMapper>(sql, mapper, "%s", id);
}

uint64_t CgthckDAO::insertIntoBill(const CgthckDO& iobj)
{
	// 生成ID
	SnowFlake sf(1, 5);
	uint64_t id = sf.nextId();
	string strId = to_string(id);

	string sql = "INSERT INTO " + string{ DATABASE1 } + " (`id`, `bill_no`, `bill_date`, `supplier_id`, `stock_io_type`) VALUES (?, ?, ?, ?, ?)";
	sqlSession->executeInsert(sql, "%s%s%s%s%s", strId, iobj.getBillNo(), iobj.getBillDate(), iobj.getSupplierId(), iobj.getSrcBillType());
	return id;
}

int CgthckDAO::insertIntoEntry(const CgthckEntryDO& iobj)
{
	string sql = "INSERT INTO" + string{ DATABASE2 } + " (`mid`, `entry_no`, `material_id`, `batch_no`, `warehouse_id`, `stock_io_direction`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", iobj.getMid(), iobj.getEntryNo(), iobj.getMaterialId(), iobj.getBatchNo(), iobj.getWarehouseId(), iobj.getStockIoDirection());
}

int CgthckDAO::update(const CgthckDO& iobj)
{
	string sql{ "" };
	sql += "UPDATE " + string{ DATABASE1 } + " SET `bill_date`=?, `supplier_id`=? WHERE `bill_no`=?";
	return sqlSession->executeInsert(sql, "%s%s%s", iobj.getBillDate(), iobj.getSupplierId(), iobj.getBillNo());
}

int CgthckDAO::deleteById(const CgthckDO& iobj)
{
	return 0;
}
