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


string CgthckDAO::insertFile(const string & fileName)
{
#ifdef LINUX
	// 定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	// 定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif
	return client.uploadFile(fileName);
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
	string sql = "INSERT INTO " + string{ DATABASE1 } + " (`id`, `bill_no`, `bill_date`, `supplier_id`, `src_bill_type`, `stock_io_type`, `src_no`, `is_effective`, `is_closed`, `is_voided`, `op_dept`, `subject`, `invoice_type`, `handler`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%i%i%i%s%s%s%s", iobj.getId(), iobj.getBillNo(), iobj.getBillDate(), iobj.getSupplierId(), iobj.getSrcBillType(), iobj.getStockIoType(), iobj.getSrcNo(), iobj.getIsEffective(), iobj.getIsClosed(), iobj.getIsVoided(), iobj.getOpDept(), iobj.getSubject(), iobj.getInvoiceType(), iobj.getHandler());
	return stoull(iobj.getId());
}

int CgthckDAO::insertIntoEntry(const CgthckEntryDO& iobj)
{
	string sql = "INSERT INTO " + string{ DATABASE2 } + " (`id`, `mid`, `bill_no`, `entry_no`, `material_id`, `batch_no`, `warehouse_id`, `stock_io_direction`, `unit_id`, `settle_qty`, `tax_rate`, `price`, `discount_rate`, `tax`, `settle_amt`, `qty`, `cost`, `invoiced_amt`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%d%d%d%d%d%d%d%d%d", iobj.getId(), iobj.getMid(), iobj.getBillNo(), iobj.getEntryNo(), iobj.getMaterialId(), iobj.getBatchNo(), iobj.getWarehouseId(), iobj.getStockIoDirection(), iobj.getUnitId(), iobj.getSettleQty(), iobj.getTaxRate(), iobj.getPrice(), iobj.getDiscountRate(), iobj.getTax(), iobj.getSettleAmt(), iobj.getQty(), iobj.getCost(), iobj.getInvoicedAmt());
}

int CgthckDAO::update(const CgthckDO& iobj)
{
	return 0;
}

int CgthckDAO::deleteById(const CgthckDO& iobj)
{
	return 0;
}
