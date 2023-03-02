/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CgrkDAO.h"
#include <sstream>
#include "../../dao/Cgrk/StkIoMapper.h"
#include "../../dao/Cgrk/StkIoEntryMapper.h"
#include "../../dao/Cgrk/PurOrderMapper.h"
#include "../../dao/Cgrk/PurOrderEntryMapper.h"
#include "../../dao/StringMapper.h"

//定义宏
#define BILL_LIST_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1 AND LEFT(bill_no,4)='CGRK' "; \
if (!obj.getBillNo().empty()) { \
	sql << " AND bill_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo()); \
} \
if ((!obj.getBillDateStart().empty())&&(!obj.getBillDateEnd().empty())) { \
	sql << " AND DATE(bill_date) BETWEEN ? "; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDateStart()); \
	sql << "AND ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDateEnd()); \
} \
if (!obj.getSubject().empty()) { \
	sql << " AND subject=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (!obj.getSupplierId().empty()) { \
	sql << " AND supplier_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSupplierId()); \
} \
if (!obj.getBillStage().empty()) { \
	sql << " AND bill_stage=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillStage()); \
} \
if (obj.getIsEffective() != -1) { \
	sql << " AND is_effective=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (obj.getIsVoided() != -1) { \
	sql << " AND is_voided=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsVoided()); \
} \
if (obj.getIsClosed() != -1) { \
	sql << " AND is_closed=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
}





//查询单据列表
std::list<StkIoDO> CgrkDAO::selectBillList(const QueryCgrkBillListQuery query)
{
	stringstream sql;
	sql << "SELECT * FROM stk_io";
	BILL_LIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query.getPageIndex() - 1) * query.getPageSize()) << "," << query.getPageSize();
	StkIoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<StkIoDO, StkIoMapper>(sqlStr, mapper, params);
}

//高级查询单据列表
std::list<StkIoDO> CgrkDAO::selectBillListAnvanced(const QueryCgrkBillListAdvancedQuery& query)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT * FROM stk_io WHERE 1=1 ";
	for (auto& condition : query.getConditionsList())
	{
		sql << query.getLogic()<<" ";
		sql << condition.getField()<<condition.getOperator1()<<"? ";
		SQLPARAMS_PUSH(params, "s", std::string, condition.getValue());

	}

	sql << " LIMIT " << ((query.getPageIndex() - 1) * query.getPageSize()) << "," << query.getPageSize();
	StkIoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<StkIoDO, StkIoMapper>(sqlStr, mapper, params);
}

//查询单个单据列表信息
list<StkIoDO> CgrkDAO::selectBillListByBillNo(string BillNo)
{
	stringstream sql;
	sql << "SELECT * FROM stk_io ";
	SqlParams params;
	if (BillNo != "")
	{
		sql << "WHERE bill_no=?";
		SQLPARAMS_PUSH(params, "s", std::string, BillNo);
	}
	StkIoMapper mapper;
	string sqlStr = sql.str();
	return  sqlSession->executeQuery<StkIoDO, StkIoMapper>(sqlStr, mapper, params);

}

//查询单据详细信息（分录信息）
list<StkIoEntryDO> CgrkDAO::selectBillDetails(string BillNo)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT * FROM stk_io_entry WHERE bill_no =? " ;
	SQLPARAMS_PUSH(params, "s", std::string, BillNo);
	string sqlStr = sql.str();
	StkIoEntryMapper mapper;
	return  sqlSession->executeQuery<StkIoEntryDO, StkIoEntryMapper>(sqlStr, mapper, params);

}

//查询采购订单列表
list<PurOrderDO> CgrkDAO::selectPurOrderList(const QueryPurOrderListQuery& query)
{
	stringstream sql;
	SqlParams params;
	//拼接sql语句
	sql << "SELECT id,bill_no,bill_date,pur_type,payment_method,prepayment_bal,settle_method,delivery_time,delivery_place,delivery_method,in_qty,in_cost,";
	sql << "invoiced_amt,invoice_type,amt,is_closed,op_dept,operator,qty,remark,settle_amt,settled_amt,src_no,subject,supplier_id	FROM pur_order ";
	sql << "WHERE 1=1 ";
	if (!query.getBillNo().empty()) {
		
		sql << " AND bill_no=?"; 
		SQLPARAMS_PUSH(params, "s", std::string, query.getBillNo());
	} 
	if ((!query.getBillDateStart().empty()) && (!query.getBillDateEnd().empty())) {
			
		sql << " AND DATE(bill_date) BETWEEN ? "; 
		SQLPARAMS_PUSH(params, "s", std::string, query.getBillDateStart());
		sql << "AND ?"; 
		SQLPARAMS_PUSH(params, "s", std::string, query.getBillDateEnd());
	} 
	if (!query.getPurType().empty()) {

		sql << " AND pur_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query.getPurType());
	}
	if (!query.getPaymentMethod().empty()) {

		sql << " AND payment_method=?";
		SQLPARAMS_PUSH(params, "s", std::string, query.getPaymentMethod());
	}
	if (!query.getSettleMethod().empty()) {

		sql << " AND settle_method=?";
		SQLPARAMS_PUSH(params, "s", std::string, query.getSettleMethod());
	}
	if ((!query.getDeliveryTimeStart().empty()) && (!query.getDeliveryTimeEnd().empty())) {

		sql << " AND DATE(delivery_time) BETWEEN ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query.getDeliveryTimeStart());
		sql << "AND ?";
		SQLPARAMS_PUSH(params, "s", std::string, query.getDeliveryTimeEnd());
	}
	if (!query.getDeliveryMethod().empty()) {

		sql << " AND delivery_method=?";
		SQLPARAMS_PUSH(params, "s", std::string, query.getDeliveryMethod());
	}
	if (!query.getInvoiceType().empty()) {

		sql << " AND invoice_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query.getInvoiceType());
	}
	sql << " LIMIT " << ((query.getPageIndex() - 1) * query.getPageSize()) << "," << query.getPageSize();
	string sqlStr = sql.str();
	PurOrderMapper mapper;
	return  sqlSession->executeQuery<PurOrderDO, PurOrderMapper>(sqlStr, mapper, params);

}

//查询采购订单分录列表
list<PurOrderEntryDO> CgrkDAO::selectPurOrderEntry(const QueryPurOrderEntryQuery& query)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT * FROM pur_order_entry ";
	sql << "WHERE bill_no =?";
	SQLPARAMS_PUSH(params, "s", std::string, query.getBillNo());
	string sqlStr = sql.str();
	PurOrderEntryMapper mapper;
	return  sqlSession->executeQuery<PurOrderEntryDO, PurOrderEntryMapper>(sqlStr, mapper, params);

}

int CgrkDAO::insertCgrkBill(const StkIoDO& iObj)
{

	string sql = "INSERT INTO `stk_io` (`id`,`bill_no`,`bill_date`,`src_bill_type`,`src_bill_id`,`src_no`,`subject`,`stock_io_type`,`op_dept`,`operator`,`handler`,`has_rp`,`has_swell`,`supplier_id`,`invoice_type`,`cost`,`remark`,`is_auto`,`bill_stage`,`attachment`,`is_effective`,`is_closed`,`is_voided`,`sys_org_code`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%i%i%s%s%d%s%i%s%s%i%i%i%s%s%s",
		iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSrcBillType(), iObj.getSrcBillId(), iObj.getSrcNo(), iObj.getSubject(), iObj.getStockIoType(), iObj.getOpDept(), iObj.getOperator1(), iObj.getHandler(), iObj.getHasRp(), iObj.getHasSwell(), iObj.getSupplierId(), iObj.getInvoiceType(), iObj.getCost(), iObj.getRemark(), iObj.getIsAuto(), iObj.getBillStage(), iObj.getAttachment(), iObj.getIsEffective(),iObj.getIsClosed(), iObj.getIsVoided(), iObj.getSysOrgCode(), iObj.getCreateBy(), iObj.getCreateTime());
}

int CgrkDAO::insertCgrkBillEntry(const StkIoEntryDO& iObj)
{
	string sql = "INSERT INTO `stk_io_entry` (`id`,`mid`,`bill_no`,`entry_no`,`src_bill_type`,`src_bill_id`,`src_entry_id`,`src_no`,`material_id`,`batch_no`,`warehouse_id`,`stock_io_direction`,`supplier_id`,`unit_id`,`swell_qty`,`qty`,`expense`,`cost`,`settle_qty`,`tax_rate`,`price`,`discount_rate`,`tax`,`settle_amt`,`invoiced_qty`,`invoiced_amt`,`remark`,`custom1`,`custom2`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%s%s%s%s%d%d%d%d%d%d%d%d%d%d%d%d%s%s%s",
		iObj.getId(), iObj.getMid(), iObj.getBillNo(), iObj.getEntryNo(),iObj.getSrcBillType(),iObj.getSrcBillId(),iObj.getSrcEntryId(),iObj.getSrcNo(), iObj.getMaterialId(), iObj.getBatchNo(), iObj.getWarehouseId(), iObj.getStockIoDirection(),iObj.getSupplierId(), iObj.getUnitId(),iObj.getSwellQty(),iObj.getQty(),iObj.getExpense(), iObj.getCost(),iObj.getSettleQty(),iObj.getTaxRate(), iObj.getPrice(),iObj.getDiscountRate(),iObj.getTax(),iObj.getSettleAmt(),iObj.getInvoicedQty(),iObj.getInvoicedAmt(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2());

}

int CgrkDAO::updateCgrkBill(const StkIoDO& iObj)
{
	stringstream sql;
	sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?,`bill_date`=?,`subject`=?,`attachment`=?,`remark`=?,`operator`=?,`op_dept`=?,`supplier_id`=?,src_no=?,src_bill_type=?,src_bill_id=?,invoice_type=? ,handler=?,has_swell=?,is_effective=?,is_closed=?,bill_stage=? WHERE bill_no = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy());
	SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime());
	SQLPARAMS_PUSH(params, "s", string, iObj.getBillDate());
	SQLPARAMS_PUSH(params, "s", string, iObj.getSubject());
	SQLPARAMS_PUSH(params, "s", string, iObj.getAttachment());
	SQLPARAMS_PUSH(params, "s", string, iObj.getRemark());
	SQLPARAMS_PUSH(params, "s", string, iObj.getOperator1());
	SQLPARAMS_PUSH(params, "s", string, iObj.getOpDept());
	SQLPARAMS_PUSH(params, "s", string, iObj.getSupplierId());
	SQLPARAMS_PUSH(params, "s", string, iObj.getSrcNo());
	SQLPARAMS_PUSH(params, "s", string, iObj.getSrcBillType());
	SQLPARAMS_PUSH(params, "s", string, iObj.getSrcBillId());
	SQLPARAMS_PUSH(params, "s", string, iObj.getInvoiceType());
	SQLPARAMS_PUSH(params, "s", string, iObj.getHandler());
	SQLPARAMS_PUSH(params, "i", int, iObj.getHasSwell());
	SQLPARAMS_PUSH(params, "i", int, iObj.getIsEffective());
	SQLPARAMS_PUSH(params, "i", int, iObj.getIsClosed());
	SQLPARAMS_PUSH(params, "s", string, iObj.getBillStage());
	SQLPARAMS_PUSH(params, "s", string, iObj.getBillNo());
	// 解析条件

	return sqlSession->executeUpdate(sql.str(), params);

}


//通过源单号查询源单id
string CgrkDAO::selectSrcBillIdBySrcNo(const string& srcNo)
{
	string sql = "SELECT id FROM  pur_order WHERE src_no=?";
	StringMapper mapper;
	list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", srcNo);
	if (ret.empty()) {
		return "";
	}
	return *ret.begin();
}

//通过源单号查询源单类型
string CgrkDAO::selectSrcBillTypeBySrcNo(const string& srcNo)
{
	string sql = "SELECT pur_type FROM  pur_order WHERE src_no=?";
	StringMapper mapper;
	list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", srcNo);
	if (ret.empty()) {
		return "";
	}
	return *ret.begin();
}
//查询用户部门
string CgrkDAO::selectOpDeptById(const string& id)
{
	string sql = "SELECT sys_depart.org_code FROM  sys_user_depart,sys_depart WHERE sys_user_depart.user_id =? AND sys_user_depart.dep_id=sys_depart.id";
	StringMapper mapper;
	list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", id);
	if (ret.empty()) {
		return "";
	}
	return *ret.begin();
}
string CgrkDAO::selectIdBySrcNo(const string& srcNo)
{
	string sql = "SELECT id FROM  stk_io WHERE src_no=?";
	StringMapper mapper;
	list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", srcNo);
	if (ret.empty()) {
		return "";
	}
	return *ret.begin();
}


//删除采购入库单据
uint64_t CgrkDAO::deleteCgrkBill(const string& billNo)
{

	string sql = "DELETE FROM stk_io WHERE bill_no=?";
	string sql2 = "DELETE FROM stk_io_entry WHERE bill_no=?";
	return (sqlSession->executeUpdate(sql, "%s", billNo) + sqlSession->executeUpdate(sql2, "%s", billNo));
}

//删除单据详细信息

int CgrkDAO::deleteCgrkBillEntry(const string& billNo)
{
	string sql = "DELETE FROM stk_io_entry WHERE bill_no=?";
	return sqlSession->executeUpdate(sql, "%s", billNo);
}
