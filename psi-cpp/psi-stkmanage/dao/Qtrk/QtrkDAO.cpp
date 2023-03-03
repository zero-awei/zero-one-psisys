#include "stdafx.h"
#include "QtrkDAO.h"
#include <sstream>

// 定义条件解析宏，解析UPDATE stk_io 的条件，减少重复代码
#define UPDATE_STKIO_TEARM_PARSE(obj, sql) \
if (!obj.getSupplierId().empty()) { \
    sql << " ,`supplier_id`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getSupplierId()); \
} \
if (!obj.getHandler().empty()) { \
    sql << " ,`handler`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getHandler()); \
} \
if (!obj.getBillStage().empty()) { \
    sql << " ,`bill_stage`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getBillStage()); \
} \
if (!obj.getApprover().empty()) { \
    sql << " ,`approver`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprover()); \
} \
if (!obj.getApprovalResultType().empty()) { \
    sql << " ,`approval_result_type`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprovalResultType()); \
} \
if (!obj.getApprovalRemark().empty()) { \
    sql << " ,`approval_remark`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprovalRemark()); \
} \
if (obj.getIsEffective() != -1) { \
    sql << " ,`is_effective`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (!obj.getEffectiveTime().empty()) { \
    sql << " ,`effective_time`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getEffectiveTime()); \
} \
if (obj.getIsClosed() != -1) { \
    sql << " ,`is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
} \
sql << " WHERE `bill_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, iObj.getBillNo());

int QtrkDAO::insert(const StkIoDO& iObj)
{
	string sql = "INSERT INTO `stk_io` (`id`,`bill_no`,`bill_date`,`subject`,`stock_io_type`, `handler`,`supplier_id`,`cost`,`remark`,`bill_stage`,`attachment`,`sys_org_code`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%d%s%s%s%s%s%s",
		iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSubject(), iObj.getStockIoType(), iObj.getHandler(), iObj.getSupplierId(), iObj.getCost(), iObj.getRemark(), iObj.getBillStage(), iObj.getAttachment(), iObj.getSysOrgCode(), iObj.getCreateBy(), iObj.getCreateTime());
}

int QtrkDAO::insert(const StkIoEntryDO& iObj)
{
    string sql = "INSERT INTO `stk_io_entry` (`id`,`mid`,`bill_no`,`entry_no`,`material_id`,`batch_no`,`warehouse_id`,`stock_io_direction`,`supplier_id`,`unit_id`,`qty`,`price`,`cost`,`remark`,`custom1`,`custom2`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%d%d%d%s%s%s",
        iObj.getId(), iObj.getMid(), iObj.getBillNo(), iObj.getEntryNo(), iObj.getMaterialId(), iObj.getBatchNo(), iObj.getWarehouseId(), iObj.getStockIoDirection(), iObj.getSupplierId(), iObj.getUnitId(), iObj.getQty(), iObj.getPrice(),iObj.getCost(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2());
}

int QtrkDAO::updateApproval(const StkIoDO& iObj)
{
    stringstream sql;
    sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?";
    SqlParams params;
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy());
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime());
    // 解析条件
    UPDATE_STKIO_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int QtrkDAO::update(const StkIoDO& iObj)
{
    stringstream sql;
    sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?,`bill_date`=?,`subject`=?,`attachment`=?,`remark`=?";
    SqlParams params;
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy());
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime());
    SQLPARAMS_PUSH(params, "s", string, iObj.getBillDate());
    SQLPARAMS_PUSH(params, "s", string, iObj.getSubject());
    SQLPARAMS_PUSH(params, "s", string, iObj.getAttachment());
    SQLPARAMS_PUSH(params, "s", string, iObj.getRemark());
    // 解析条件
    UPDATE_STKIO_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int QtrkDAO::update(const StkIoEntryDO& iObj)
{
    string sql = "UPDATE `stk_io_entry` SET `supplier_id`=?,`material_id`=?,`warehouse_id`=?,`unit_id`=?,`qty`=?,`price`=?,`cost`=?,`remark`=?,`custom1`=?,`custom2`=? WHERE `bill_no`=? AND `entry_no`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%d%d%d%s%s%s%s%i", iObj.getSupplierId(), iObj.getMaterialId(), iObj.getWarehouseId(), iObj.getUnitId(), iObj.getQty(),iObj.getPrice(), iObj.getCost(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2(), iObj.getBillNo(), iObj.getEntryNo());
}

int QtrkDAO::deleteDetailById(const string& billNo, const int& entryNo)
{
    string sql = "DELETE FROM `stk_io_entry` WHERE `bill_no`=? AND `entry_no`=?";
    return sqlSession->executeUpdate(sql, "%s%i", billNo, entryNo);
}
