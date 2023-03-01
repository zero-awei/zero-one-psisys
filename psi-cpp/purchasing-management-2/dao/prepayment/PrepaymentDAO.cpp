#include "stdafx.h"
#include "PrepaymentDAO.h"
#include "PrepaymentMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \


//页数统计
uint64_t PrepaymentDAO::count(const PurOrderDO & iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `pur_order`";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//分页查询采购单列表
list<PurOrderDO> PrepaymentDAO::selectWithPage(const PurOrderDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM `pur_order`";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurOrderMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurOrderDO, PurOrderMapper>(sqlStr, mapper, params);
}

//查询指定单据详细信息
list<PurOrderDO> PrepaymentDAO::selectByBill_no(const PurOrderDO& obj)
{
	string sql = "SELECT * FROM `pur_order` WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PurOrderDetailMapper mapper;
	return sqlSession->executeQuery<PurOrderDO, PurOrderDetailMapper>(sql, mapper, "%s", obj.getBill_no());
}


// 删除预付申请单
int PrepaymentDAO::deleteById(const PrepaymentDO& uObj)
{
	string sql = "DELETE FROM `fin_payment_req` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}

