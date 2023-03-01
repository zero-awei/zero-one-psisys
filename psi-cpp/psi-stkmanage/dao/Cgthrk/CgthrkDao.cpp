#include "stdafx.h"
#include "CgthrkDao.h"
#include "QueryCgthrkBillListDOMapper.h"
#include"QueryCgthrkBillListDetailedMapper.h"
#include <sstream>

uint64_t CgthrkDao::count(const QueryCgthrkBillListDO& Obj) {
	stringstream sql;
		sql << "SELECT COUNT(*) FROM stk_io,sys_depart,bas_supplier";//需要多表联查（待修改）
	

		//组装sql
		SqlParams params;
		sql << " WHERE sys_depart.org_code = stk_io.op_dept and stk_io.supplier_id = bas_supplier.id and stk_io.sys_org_code = sys_depart.org_code";
		if (!Obj.getId().empty()) {
				sql << " AND `bill_no`=?"; 
				params.push_back(SqlParam("s", std::make_shared<string>(Obj.getId())));
		} 

		if (!Obj.getTheme().empty()) {
			sql << " AND `subject`=?";
			params.push_back(SqlParam("s", std::make_shared<string>(Obj.getTheme())));
		}

		if (!Obj.getStage().empty()) {
			sql << " AND `bill_stage`=?";
			params.push_back(SqlParam("s", std::make_shared<string>(Obj.getStage())));
		}

		if (Obj.getIsEffective()!=-1) {
			sql << " AND `is_effective`=?";
			params.push_back(SqlParam("s", std::make_shared<int>(Obj.getIsEffective())));
		}
		if (Obj.getIsClosed() != -1) {
			sql << " AND `is_closed`=?";
			params.push_back(SqlParam("s", std::make_shared<int>(Obj.getIsClosed())));
		}
		if (Obj.getIsVoided() != -1) {
			sql << " AND `is_voided`=?";
			params.push_back(SqlParam("s", std::make_shared<int>(Obj.getIsVoided())));
		}
		if (!Obj.getBeginData().empty()) {
			sql << " AND `bill_date`>=?";
			params.push_back(SqlParam("s", std::make_shared<string>(Obj.getBeginData())));
		}
		if (!Obj.getEndData().empty()) {
			sql << " AND `bill_date`<=?";
			params.push_back(SqlParam("s", std::make_shared<string>(Obj.getEndData())));
		}

		string sqlStr = sql.str();
		return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<QueryCgthrkBillListReturnDO> CgthrkDao::selectCgthckBillList(const QueryCgthrkBillListDO& Obj, uint64_t pageIndex, uint64_t pageSize) {
	stringstream sql;
	sql << "SELECT stk_io.bill_no,stk_io.bill_date,stk_io.subject,stk_io.src_no,bas_supplier.`name`,sys_depart.depart_name,operator,cost,settle_amt,settled_amt,invoiced_amt,invoice_type,`handler`,bill_stage,is_effective,is_closed,is_voided,is_auto,is_rubric,stk_io.remark,effective_time,approver, stk_io.create_time, stk_io.create_by, sys_depart.depart_name, stk_io.update_time, stk_io.update_by from stk_io, sys_depart, bas_supplier";

	//组装sql
	SqlParams params;
	sql << " WHERE sys_depart.org_code = stk_io.op_dept and stk_io.supplier_id = bas_supplier.id and stk_io.sys_org_code = sys_depart.org_code";
	if (!Obj.getId().empty()) {
		sql << " AND `bill_no`=?";
		params.push_back(SqlParam("s", std::make_shared<string>(Obj.getId())));
	}

	if (!Obj.getTheme().empty()) {
		sql << " AND `subject`=?";
		params.push_back(SqlParam("s", std::make_shared<string>(Obj.getTheme())));
	}

	if (!Obj.getStage().empty()) {
		sql << " AND `bill_stage`=?";
		params.push_back(SqlParam("s", std::make_shared<string>(Obj.getStage())));
	}

	if (Obj.getIsEffective() != -1) {
		sql << " AND `is_effective`=?";
		params.push_back(SqlParam("s", std::make_shared<int>(Obj.getIsEffective())));
	}
	if (Obj.getIsClosed() != -1) {
		sql << " AND `is_closed`=?";
		params.push_back(SqlParam("s", std::make_shared<int>(Obj.getIsClosed())));
	}
	if (Obj.getIsVoided() != -1) {
		sql << " AND `is_voided`=?";
		params.push_back(SqlParam("s", std::make_shared<int>(Obj.getIsVoided())));
	}
	if (!Obj.getBeginData().empty()) {
		sql << " AND `bill_date`>=?";
		params.push_back(SqlParam("s", std::make_shared<string>(Obj.getBeginData())));
	}
	if (!Obj.getEndData().empty()) {
		sql << " AND `bill_date`<=?";
		params.push_back(SqlParam("s", std::make_shared<string>(Obj.getEndData())));
	}
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	QueryCgthrkBillListDOMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<QueryCgthrkBillListReturnDO, QueryCgthrkBillListDOMapper>(sqlStr, mapper, params);
}

QueryCgthrkBillDetailedReturnDO CgthrkDao::selectCgthckBillListDetailed(const BillDetailedDO& Obj) {
	QueryCgthrkBillDetailedReturnDO q;
	stringstream sql;
	sql << "SELECT src_entry_id, material_id,batch_no, warehouse_id,unit_id,qty,tax_rate,price,discount_rate,tax,settle_amt,settle_qty,expense,invoiced_amt,invoiced_qty,invoiced_amt,remark,custom1,custom2 FROM `stk_io_entry`";
	sql << " where 1=1";
	//组装sql
	SqlParams params;
	if (!Obj.getBillNo().empty()) {
		sql << " AND `bill_no`=?";
		params.push_back(SqlParam("s", std::make_shared<string>(Obj.getBillNo())));
	}
	QueryCgthrkBillListDetailedMapper mapper;
	string sqlStr = sql.str();
	list<BillEntryDetailedVO> entry = sqlSession->executeQuery<BillEntryDetailedVO, QueryCgthrkBillListDetailedMapper>(sqlStr, mapper, params);

	stringstream sql1;
	sql1 << "SELECT stk_io.bill_no,stk_io.bill_date,stk_io.subject,stk_io.src_no,bas_supplier.`name`,sys_depart.depart_name,operator,cost,settle_amt,settled_amt,invoiced_amt,invoice_type,`handler`,bill_stage,is_effective,is_closed,is_voided,is_auto,is_rubric,stk_io.remark,effective_time,approver, stk_io.create_time, stk_io.create_by, sys_depart.depart_name, stk_io.update_time, stk_io.update_by from stk_io, sys_depart, bas_supplier";

	//组装sql
	SqlParams params1;
	sql1 << " WHERE sys_depart.org_code = stk_io.op_dept and stk_io.supplier_id = bas_supplier.id and stk_io.sys_org_code = sys_depart.org_code";
	if (!Obj.getBillNo().empty()) {
		sql1 << " AND `bill_no`=?";
		params1.push_back(SqlParam("s", std::make_shared<string>(Obj.getBillNo())));
	}
	sqlStr = sql1.str();
	QueryCgthrkBillListDOMapper mapper2;
	list<QueryCgthrkBillListReturnDO> l = sqlSession->executeQuery<QueryCgthrkBillListReturnDO, QueryCgthrkBillListDOMapper>(sqlStr, mapper2, params1);

	q.setBillNo(l.front().getBillNo());
	q.setBillDate(l.front().getBillDate());
	q.setSubject(l.front().getSubject());
	q.setSrcNo(l.front().getSrcNo());
	q.setSupplierId(l.front().getSupplierId());
	q.setOptDept(l.front().getOptDept());
	q.setSrcOperator(l.front().getSrcOperator());
	q.setInAmt(l.front().getInAmt());
	q.setSettleAmt(l.front().getSettleAmt());
	q.setSettledAmt(l.front().getSettledAmt());
	q.setInvoicedAmt(l.front().getInvoicedAmt());
	q.setInvoiceType(l.front().getInvoiceType());
	q.setHandler(l.front().getHandler());
	q.setBillStage(l.front().getBillStage());
	q.setIsEff(l.front().getIsEff());
	q.setIsClosed(l.front().getIsClosed());
	q.setIsVoided(l.front().getIsVoided());
	q.setIsAuto(l.front().getIsAuto());
	q.setIsRubric(l.front().getIsRubric());
	q.setRemark(l.front().getRemark());
	q.setEffTime(l.front().getEffTime());
	q.setApprover(l.front().getApprover());
	q.setCreateTime(l.front().getCreateTime());
	q.setCreateBy(l.front().getCreateBy());
	q.setSysOrgCode(l.front().getSysOrgCode());
	q.setUpdateTime(l.front().getUpdateTime());
	q.setUpdateBy(l.front().getUpdateBy());
	q.setDetail(entry);
	return q;

}