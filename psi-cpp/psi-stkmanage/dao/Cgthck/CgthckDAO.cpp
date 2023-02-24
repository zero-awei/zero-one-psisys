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

// 定义更新逻辑解析宏, 减少重复代码
#define UPDATE_CGTHCK_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" UPDATE `stk_io` SET "; \
if (!obj.getBillDate().empty()) { \
    sql << "`bill_date`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getBillDate()); \
} \
if (!obj.getSupplierId().empty()) { \
	sql << ", `supplier_id`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getSupplierId()); \
}\
if (!obj.getSubject().empty()) { \
	sql << ", `subject`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getSubject()); \
}\
if (!obj.getOpDept().empty()) { \
	sql << ", `op_dept`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getOpDept()); \
}\
if (!obj.getSrcNo().empty()) { \
	sql << ", `src_no`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getSrcNo()); \
}\
if (!obj.getHandler().empty()) { \
	sql << ", `handler`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getHandler()); \
}\
if (!obj.getBillStage().empty()) { \
    sql << ", `bill_stage`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getBillStage()); \
} \
if (!obj.getAttachment().empty()) { \
    sql << ", `attachment`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getAttachment()); \
} \
if (!obj.getRemark().empty()) {\
	sql << ", `remark`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getRemark()); \
} \
if (obj.getIsEffective() == 1) { \
    sql << ", `is_effective`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (obj.getIsClosed() == 1) { \
    sql << ", `is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
} \
if (obj.getIsVoided() == 1) { \
    sql << ", `is_voided`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsVoided()); \
} \
sql << " WHERE `bill_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, obj.getBillNo());

// 定义条件解析宏, 解析UPDATE stk_io_entry 的条件, 减少重复代码
#define UPDATE_CGHTCK_ENTRY_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" UPDATE `stk_io_entry` SET "; \
if (!obj.getEntryNo().empty()) { \
    sql << "`entry_no`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getEntryNo()); \
} \
if (obj.getSettleQty()) { \
    sql << ", `settle_qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettleQty()); \
} \
if (obj.getTaxRate()) { \
    sql << ", `tax_rate`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getTaxRate()); \
} \
if (obj.getSettleAmt()) { \
    sql << ", `settle_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettleAmt()); \
} \
if (obj.getQty()) { \
    sql << ", `qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getQty()); \
} \
if (obj.getSettleAmt()) { \
    sql << ", `settle_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettleAmt()); \
} \
if (!obj.getRemark().empty()) { \
    sql << ", `remark`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getRemark()); \
} \
if (!obj.getCustom1().empty()) { \
    sql << ", `custom1`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getCustom1()); \
} \
if (!obj.getCustom2().empty()) { \
    sql << ", `custom2`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getCustom2()); \
} \
sql << " WHERE `batch_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, obj.getBatchNo());


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

bool CgthckDAO::deleteFile(const string& fileName)
{
#ifdef LINUX
	// 定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	// 定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif
	return client.deleteFile(fileName);
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

uint64_t CgthckDAO::insert(const CgthckDO& iobj)
{
	string sql = "INSERT INTO " + string{ DATABASE1 } + " (`id`, `bill_no`, `bill_date`, `supplier_id`, `src_bill_type`, `stock_io_type`, `src_no`, `is_effective`, `is_closed`, `is_voided`, `op_dept`, `subject`, `invoice_type`, `handler`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	int row = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%i%i%s%s%s%s", iobj.getId(), iobj.getBillNo(), iobj.getBillDate(), iobj.getSupplierId(), iobj.getSrcBillType(), iobj.getStockIoType(), iobj.getSrcNo(), iobj.getIsEffective(), iobj.getIsClosed(), iobj.getIsVoided(), iobj.getOpDept(), iobj.getSubject(), iobj.getInvoiceType(), iobj.getHandler());
	return row == 0 ? row : stoull(iobj.getId());
}

int CgthckDAO::insert(const CgthckEntryDO& iobj)
{
	string sql = "INSERT INTO " + string{ DATABASE2 } + " (`id`, `mid`, `bill_no`, `entry_no`, `material_id`, `batch_no`, `warehouse_id`, `stock_io_direction`, `unit_id`, `settle_qty`, `tax_rate`, `price`, `discount_rate`, `tax`, `settle_amt`, `qty`, `cost`, `invoiced_amt`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%d%d%d%d%d%d%d%d%d", iobj.getId(), iobj.getMid(), iobj.getBillNo(), iobj.getEntryNo(), iobj.getMaterialId(), iobj.getBatchNo(), iobj.getWarehouseId(), iobj.getStockIoDirection(), iobj.getUnitId(), iobj.getSettleQty(), iobj.getTaxRate(), iobj.getPrice(), iobj.getDiscountRate(), iobj.getTax(), iobj.getSettleAmt(), iobj.getQty(), iobj.getCost(), iobj.getInvoicedAmt());
}

int CgthckDAO::update(const CgthckDO& iobj)
{
	stringstream sql;
	UPDATE_CGTHCK_TERAM_PARSE(iobj, sql);
	return sqlSession->executeUpdate(sql.str(), params);
}

int CgthckDAO::update(const CgthckEntryDO& iobj)
{
	stringstream sql;
	UPDATE_CGHTCK_ENTRY_TERAM_PARSE(iobj, sql);
	return sqlSession->executeUpdate(sql.str(), params);
}

int CgthckDAO::deleteById(const CgthckDO& iobj)
{
	return 0;
}
