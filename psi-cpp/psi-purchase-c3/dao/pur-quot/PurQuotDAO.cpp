#include "stdafx.h"
#include "PurQuotDAO.h"
#include <sstream>
//mapper
#include "PurQuotFindBillMapper.h"
#include "PurQuotFindDetailBillMapper.h"
#include "PurQuotListMapper.h"
#include "PurQuotDividedListMapper.h"


uint64_t PurQuotDAO::count(const PurQuotDO & iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_quot";
	SqlParams params;
	sql << " WHERE 1=1";
	if (! iObj.getSubject().empty()) {
		sql << " AND subject=?";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getSubject());
	}
	if (! iObj.getBill_stage().empty()) {
		sql << " AND bill_stage=?";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getBill_stage());
	}
	if (iObj.getIs_effective() != -1) {
		sql << " AND is_effective=?";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getIs_effective());
	}
	if (iObj.getIs_closed() != -1) {
		sql << " AND is_closed=?";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getIs_closed());
	}
	if (iObj.getIs_voided() != -1) {
		sql << " AND is_voided=?";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getIs_voided());
	}
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//获取多个PurQuotFindBillDO对象
list<PurQuotDO> PurQuotDAO::selectPurQuotFindBillDO(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize) {
	stringstream sql;
	sql << "SELECT bill_no, bill_date, subject,src_no,supplier_name, delivery_time,qty,amt,bill_stage, is_effective, is_closed, is_voided, \
	payment_method, delivery_place, contact,phone, fax, email, remark, is_auto, is_rubric, effective_time, approver, create_time, \
	create_by, sys_org_code, update_time, update_by FROM pur_quot";
	SqlParams params; 
	sql<<" WHERE 1=1"; 
	if (! obj.getBill_no().empty()) { 
		sql << " AND `bill_no`=?"; 
		SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); 
	}
	//日期存疑, 暂时不写
	if (! obj.getSubject().empty()) { 
		sql << " AND subject=?"; 
		SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); 
	}
	if (! obj.getBill_stage().empty()) {
		sql << " AND bill_stage=?";
		SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_stage());
	}
	if (obj.getIs_effective() != -1) {
		sql << " AND is_effective=?";
		SQLPARAMS_PUSH(params, "s", std::string, obj.getIs_effective());
	}
	if (obj.getIs_closed() != -1) {
		sql << " AND is_closed=?";
		SQLPARAMS_PUSH(params, "s", std::string, obj.getIs_closed());
	}
	if (obj.getIs_voided() != -1) {
		sql << " AND is_voided=?";
		SQLPARAMS_PUSH(params, "s", std::string, obj.getIs_voided());
	}
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurQuotFindBillMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotDO, PurQuotFindBillMapper>(sqlStr, mapper, params);
}

