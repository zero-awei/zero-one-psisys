#include "stdafx.h"
#include "CgthckDAO.h"
#include <sstream>

// 测试中

//定义条件解析宏，减少重复代码
#define QUERY_CGRK_BILL_LIST_TERAM_PARSE(obj, sql) \
SqlParams params;  \
sql << " WHERE 1=1"; \
if (!obj.getBillNo().empty()) { \
	sql << " AND bill_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo()); \
} \

// 定义更新逻辑解析宏, 减少重复代码
#define UPDATE_CGTHCK_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" UPDATE `stk_io` SET `update_time`=NOW()"; \
if (!obj.getBillDate().empty()) { \
    sql << ", `bill_date`=?"; \
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
if (!obj.getEffectiveTime().empty()) { \
    sql << ", `effective_time`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getEffectiveTime()); \
} \
if (!obj.getRemark().empty()) {\
	sql << ", `remark`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getRemark()); \
} \
if (obj.getIsEffective() == 1) { \
    sql << ", `is_effective`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (!obj.getApprovalRemark().empty()) { \
    sql << ", `approval_remark`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprovalRemark()); \
} \
if (!obj.getApprovalResultType().empty()) { \
    sql << ", `approval_result_type`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprovalResultType()); \
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

// 定义条件解析宏，解析UPDATE stk_io 状态的条件，减少重复代码
#define UPDATE_CGTHCK_STATUS_TEARM_PARSE(obj, sql) \
sql << "UPDATE `stk_io` SET `update_time`=NOW()"; \
SqlParams params; \
if (obj.getIsClosed() == 0 || obj.getIsClosed() == 1) { \
    sql << ", `is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
} \
if (obj.getIsVoided() == 0 || obj.getIsVoided() == 1) { \
    sql << " ,`is_voided`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsVoided()); \
} \
if (!obj.getApprover().empty()) { \
	sql << ", `approver`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getApprover()); \
} \
if (!obj.getEffectiveTime().empty()) { \
	sql << ", `effective_time`=?"; \
	SQLPARAMS_PUSH(params, "s", string, obj.getEffectiveTime()); \
} \
sql << " WHERE `bill_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, obj.getBillNo());

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

uint64_t CgthckDAO::count(const CgthckEntryDO& iobj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `stk_io_entry`";
	QUERY_CGRK_BILL_LIST_TERAM_PARSE(iobj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);

}
list<CgthckEntryDO> CgthckDAO::selectWithId(const CgthckEntryDO& iobj)
{
	stringstream sql;
	sql << "SELECT `entry_no`, `src_no`, `material_id`, `warehouse_id`, `batch_no`, `unit_id`, `settle_qty`, `tax_rate`, `price`, `discount_rate`, `tax`, `settle_amt`, `qty`, `cost`, `invoiced_qty`, `invoiced_amt`, `remark`, `custom1`, `custom2` FROM `stk_io_entry`";
	QUERY_CGRK_BILL_LIST_TERAM_PARSE(iobj, sql);
	CgthckMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CgthckEntryDO, CgthckMapper>(sqlStr, mapper, params);
}

uint64_t CgthckDAO::insert(const CgthckDO& iobj)
{
	string sql = "INSERT INTO `stk_io` (`id`, `bill_no`, `bill_date`, `supplier_id`, `src_bill_type`, `stock_io_type`, `src_no`, `is_effective`, `is_closed`, `is_voided`, `op_dept`, `subject`, `invoice_type`, `handler`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	int row = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%i%i%s%s%s%s", iobj.getId(), iobj.getBillNo(), iobj.getBillDate(), iobj.getSupplierId(), iobj.getSrcBillType(), iobj.getStockIoType(), iobj.getSrcNo(), iobj.getIsEffective(), iobj.getIsClosed(), iobj.getIsVoided(), iobj.getOpDept(), iobj.getSubject(), iobj.getInvoiceType(), iobj.getHandler());
	return row == 0 ? row : stoull(iobj.getId());
}

int CgthckDAO::insert(const CgthckEntryDO& iobj)
{
	string sql = "INSERT INTO `stk_io_entry` (`id`, `mid`, `bill_no`, `entry_no`, `material_id`, `batch_no`, `warehouse_id`, `stock_io_direction`, `unit_id`, `settle_qty`, `tax_rate`, `price`, `discount_rate`, `tax`, `settle_amt`, `qty`, `cost`, `invoiced_amt`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
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

int CgthckDAO::updateApproval(const CgthckDO& iobj)
{
	stringstream sql;
	UPDATE_CGTHCK_TERAM_PARSE(iobj, sql);
	return sqlSession->executeUpdate(sql.str(), params);
}

int CgthckDAO::updateStatus(const CgthckDO& iobj)
{
	stringstream sql;
	UPDATE_CGTHCK_STATUS_TEARM_PARSE(iobj, sql);
	return sqlSession->executeUpdate(sql.str(), params);
}

int CgthckDAO::deleteBillById(const string& billNo)
{
	string sql = "DELETE FROM `stk_io` WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%s", billNo);
}

int CgthckDAO::deleteEntryById(const string& billNo)
{
	string sql = "DELETE FROM `stk_io_entry` WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%s", billNo);
}

int CgthckDAO::deleteEntryById(const string& billNo, const string& entryNo)
{
	string sql = "DELETE FROM `stk_io_entry` WHERE `bill_no`=? AND `entry_no`=?";
	return sqlSession->executeUpdate(sql, "%s%s", billNo, entryNo);
}

uint64_t CgthckDAO::importData(const CgthckDO& iobj)
{
	string sql = "INSERT INTO `stk_io` \
				(`stock_io_type`, `has_rp`, `has_swell`, `supplier_id`, `customer_id, `invoice_type`, \
				`op_dept`, `operator`, `handler`, `version`, `settle_amt`, `settled_amt, `invoiced_amt`, \
				`is_effective`, `attachment`, `src_bill_id`, `subject`, `bill_stage`, `src_no`, `is_auto`, \
				`remark`, `bpmi_instance_id`, `is_voided`, `bill_no`, `is_rubric`, `src_bill_type,` \
				`create_time`, `effective_time`, `approver`, `update_by`, `sys_org_code`, `is_closed`, \
				`approval_result_type`, `bill_date`, `create_by`, `approval_remark`) \
				VALUES (?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?)";
	uint64_t result = sqlSession->executeInsert(sql,
					"%s%i%i%s%s%s\
					%s%s%s%i%d%d%\
					d%i%s%s%s%s\
					%s%i%s%s%i%s\
					%i%s%s%s%s%\
					%s%i%s%s%s%s",
					iobj.getStockIoType(), iobj.getHasRp(), iobj.getHasSwell(), iobj.getSupplierId(), iobj.getCustomerId(), iobj.getInvoiceType(), 
					iobj.getOpDept(), iobj.getOperator1(), iobj.getHandler(), iobj.getVersion(), iobj.getSettleAmt(), iobj.getSettledAmt(), 
					iobj.getInvoicedAmt(), iobj.getIsEffective(), iobj.getAttachment(), iobj.getSrcBillId(), iobj.getSubject(), iobj.getBillStage(), 
					iobj.getSrcNo(), iobj.getIsAuto(), iobj.getRemark(), iobj.getBpmiInstanceId(), iobj.getIsVoided(), iobj.getBillNo(), 
					iobj.getIsRubric(), iobj.getSrcBillType(), iobj.getCreateTime(), iobj.getEffectiveTime(), iobj.getApprover(), iobj.getUpdateBy(), 
					iobj.getSysOrgCode(), iobj.getIsClosed(), iobj.getApprovalResultType(), iobj.getBillDate(), iobj.getCreateBy(), iobj.getApprovalRemark());
	return result;
}

uint64_t CgthckDAO::importData(const CgthckEntryDO& iobj)
{
	string sql = "INSERT INTO `stk_io_entry` \
				(`material_id`, `batch_no`, `warehouse_id`, `stock_io_direction`, `supplier_id`, `unit_id`, \
				`swell_qty`, `qty`, `expense`, `cost`, `settle_qty`, `tax_rate`, \
				`price`, `discount_rate`, `tax`, `settle_amt`, `invoiced_qty`, `invoiced_amt`, \
				`custom1`, `src_no`, `entry_no`, `custom2`, `src_entry_id`, `src_bill_type`, \
				`remark`, `bill_no`, `mid`) \
				VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?, ?, ?, ?, \
				?, ?, ?, ?, ?, ?, ?, ?, ?)";
	uint64_t result = sqlSession->executeInsert(sql,
		"%s%s%s%s%s%s\
					%d%d%d%d%d%d\
					%d%d%d%d%d%d\
					%s%s%s%s%s%s\
					%s%s%s",
					iobj.getMaterialId(), iobj.getBatchNo(), iobj.getWarehouseId(), iobj.getStockIoDirection(), iobj.getSupplierId(), iobj.getUnitId(),
					iobj.getSwellQty(), iobj.getQty(), iobj.getExpense(), iobj.getCost(), iobj.getSettleQty(), iobj.getTaxRate(),
					iobj.getPrice(), iobj.getDiscountRate(), iobj.getTax(), iobj.getSettleAmt(), iobj.getInvoicedQty(), iobj.getInvoicedAmt(),
					iobj.getCustom1(), iobj.getSrcNo(), iobj.getEntryNo(), iobj.getCustom2(), iobj.getSrcEntryId(), iobj.getSrcBillType(),
					iobj.getRemark(), iobj.getBillNo(), iobj.getMid());
	return result;
}

list<CgthckDO> CgthckDAO::exportData(const CgthckDO& iobj)
{
	return list<CgthckDO>();
}

list<CgthckEntryDO> CgthckDAO::exportData(const CgthckEntryDO& iobj)
{
	return list<CgthckEntryDO>();
}
