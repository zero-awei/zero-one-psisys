#include "stdafx.h"
#include "CgthrkDao.h"
#include "QueryCgthrkBillListDOMapper.h"
#include <sstream>
#include"../../domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"

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