#include "stdafx.h"
#include "PurQuotDAO.h"
#include <sstream>
//mapper
#include "PurQuotFindBillMapper.h"
#include "PurQuotFindDetailBillMapper.h"
#include "PurQuotListMapper.h"
#include "PurQuotDividedListMapper.h"


uint64_t PurQuotDAO::count(const PurQuotFindBillDO & iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_quot";
	//PUR_QUOT_TERAM_PARSE(iObj, sql);
	SqlParams params;
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
list<PurQuotFindBillDO> PurQuotDAO::selectPurQuotFindBillDO(const PurQuotFindBillDO& obj, uint64_t pageIndex, uint64_t pageSize) {
	stringstream sql;
	sql << "SELECT bill_no, bill_date, subject,src_no,supplier_name, delivery_time,qty,amt,bill_stage, is_effective, is_closed, is_voided, \
	payment_method, delivery_place, contact,phone, fax, email, remark, is_auto, is_rubric, effective_time, approver, create_time, \
	create_by, sys_org_code, update_time, update_by FROM pur_quot";
	SqlParams params; 
	sql<<" WHERE 1=1"; 
	if (!obj.getBill_no().empty()) { 
		sql << " AND `bill_no`=?"; 
		SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); 
	}
	////日期这块存疑, 暂时先不写
	//if (!obj.getBill_date().empty()) { 
	//	sql << " AND Date(bill_date_begin) <=?"; 
	//	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); 
	//} 
	//if (obj.getBill_date().empty()) { 
	//	sql << " AND Date(bill_date_end) >="; 
	//	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); 
	//}
	if (obj.getSubject().empty()) { 
		sql << " AND subject=?"; 
		SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); 
	}
	if (obj.getBill_stage().empty()) {
		sql << " AND bill_stage=?";
		SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_stage());
	}
	if (obj.getIs_effective() != -1) {
		sql << " AND is_effective=?";
		SQLPARAMS_PUSH(params, "i", int, obj.getIs_effective());
	}
	if (obj.getIs_closed() != -1) {
		sql << " AND is_closed=?";
		SQLPARAMS_PUSH(params, "i", int, obj.getIs_closed());
	}
	if (obj.getIs_voided() != -1) {
		sql << " AND is_voided=?";
		SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided());
	}
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurQuotMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotFindBillDO, PurQuotMapper>(sqlStr, mapper, params);
}

