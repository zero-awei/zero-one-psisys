#include "stdafx.h"
#include "PyrkDao.h"
#include "PyrkMapper.h"
#include <sstream>
#include "FastDfsClient.h"
#include "StringMapper.h"
//#include "PyrkDAO.h"
//#include "PyrkMapper.h"
//#include <sstream>
//
////定义条件解析宏，减少重复代码
////#define SAMPLE_TERAM_PARSE(obj, sql) \
//
//uint64_t PyrkDao::count(const QueryPyrkBillListDo& Obj) {
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM sample";//需要多表联查（待修改）
//
//	SqlParams params;
//	sql << "WHERE 1=1";
//	if (!Obj.getId().empty()) {
//			sql << " AND `name`=?"; 
//			params.push_back(SqlParam(__PARAM_KEY__, std::make_shared<__VAL_TYPE__>(__VAL_VAL__)))
//	} 
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

// 定义条件解析宏，解析UPDATE stk_io 的条件，减少重复代码
#define UPDATE_STKIO_TEARM_PARSE(obj, sql) \
sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?"; \
SqlParams params; \
SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy()); \
SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime()); \
if (!obj.getBillDate().empty()) { \
    sql << " ,`bill_date`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getBillDate()); \
} \
if (!obj.getSubject().empty()) { \
    sql << " ,`subject`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getSubject()); \
} \
if (!obj.getHandler().empty()) { \
    sql << " ,`handler`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getHandler()); \
} \
if (!obj.getAttachment().empty()) { \
    sql << " ,`attachment`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getAttachment()); \
} \
if (!obj.getRemark().empty()) { \
    sql << " ,`remark`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getRemark()); \
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
if (obj.getIsEffective() == 1) { \
    sql << " ,`is_effective`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (!obj.getEffectiveTime().empty()) { \
    sql << " ,`effective_time`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getEffectiveTime()); \
} \
if (obj.getIsClosed() == 1) { \
    sql << " ,`is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
} \
if (obj.getIsVoided() == 1) { \
    sql << " ,`is_voided`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsVoided()); \
} \
sql << " WHERE `bill_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, iObj.getBillNo());

// 定义条件解析宏，解析UPDATE stk_io_entry 的条件，减少重复代码
#define UPDATE_STKIOENTRY_TEARM_PARSE(obj, sql) \
sql << "UPDATE `stk_io_entry` SET `update_by`=?,`update_time`=?"; \
SqlParams params; \

string PyrkDao::selectOrgCodeByUsername(const string& username)
{
    string sql = "SELECT d.org_code FROM sys_depart d, sys_user u, sys_user_depart ud WHERE d.id = ud.dep_id AND u.id = ud.user_id AND u.username = ?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", username);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string PyrkDao::selectBillIdByBillNo(const string& billNo)
{
    string sql = "SELECT id FROM stk_io WHERE bill_no = ?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", billNo);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string PyrkDao::selectAttachmentByBillNo(const string& billNo)
{
    string sql = "SELECT `attachment` FROM `stk_io` WHERE `bill_no`=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", billNo);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string PyrkDao::selectWarehouseIdByAuxName(const string& warehouse)
{
    string sql = "SELECT id FROM bas_warehouse WHERE aux_name=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", warehouse);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string PyrkDao::selectMaterialIdByAuxName(const string& material)
{
    string sql = "SELECT id FROM bas_material WHERE aux_name=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", material);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string PyrkDao::selectUnitIdByName(const string& unit)
{
    string sql = "SELECT id FROM bas_unit WHERE name=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", unit);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

int PyrkDao::insert(const StkIoDO& iObj)
{
    string sql = "INSERT INTO `stk_io` (`id`,`bill_no`,`bill_date`,`subject`,`stock_io_type`, `handler`,`remark`,`bill_stage`,`attachment`,`sys_org_code`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s",
        iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSubject(),iObj.getStockIoType(),iObj.getHandler(),iObj.getRemark(),iObj.getBillStage(), iObj.getAttachment(),iObj.getSysOrgCode(), iObj.getCreateBy(), iObj.getCreateTime());
}

int PyrkDao::insert(const StkIoEntryDO& iObj)
{
    string sql = "INSERT INTO `stk_io_entry` (`id`,`mid`,`bill_no`,`entry_no`,`material_id`,`batch_no`,`warehouse_id`,`stock_io_direction`,`unit_id`,`qty`,`cost`,`remark`,`custom1`,`custom2`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%d%d%s%s%s",
        iObj.getId(),iObj.getMid(),iObj.getBillNo(),atoi(iObj.getEntryNo().c_str()), iObj.getMaterialId(), iObj.getBatchNo(), iObj.getWarehouseId(), iObj.getStockIoDirection(), iObj.getUnitId(), iObj.getQty(), iObj.getCost(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2());
}

string PyrkDao::insertAttachment(const string& fileName)
{
#ifdef LINUX
    // 定义客户端对象
    FastDfsClient client("conf/client.conf", 3);
#else
    // 定义客户端对象
    FastDfsClient client("192.168.235.251");
#endif
    return client.uploadFile(fileName);
}

bool PyrkDao::deleteAttachment(const string& fileName)
{
#ifdef LINUX
    // 定义客户端对象
    FastDfsClient client("conf/client.conf", 3);
#else
    // 定义客户端对象
    FastDfsClient client("192.168.235.251");
#endif
    return client.deleteFile(fileName);
}

int PyrkDao::updateApproval(const StkIoDO& iObj)
{
    stringstream sql;
    // 解析条件
    UPDATE_STKIO_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int PyrkDao::update(const StkIoDO& iObj)
{
    stringstream sql;
    // 解析条件
    UPDATE_STKIO_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int PyrkDao::update(const StkIoEntryDO& iObj)
{
    stringstream sql;
    // 解析条件

    return 0;
}
