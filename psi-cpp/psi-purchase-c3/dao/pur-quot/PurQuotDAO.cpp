#include "stdafx.h"
#include "PurQuotDAO.h"
#include <sstream>
//mapper
#include "PurQuotFindBillMapper.h"
#include "PurQuotListMapper.h"
#include "PurQuotDividedListMapper.h"
#include "PurQuotBaseMapper.h"
#include "PurQuotDetailMapper.h"


//和PurQuotDO相关的宏
#define PUR_QUOT_TERAM_PARSE(obj, sql) \
SqlParams params;  \
sql << " WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND bill_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getSubject().empty()) { \
	sql << " AND `subject`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (!obj.getBill_stage().empty()) { \
	sql << " AND bill_stage=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_stage()); \
} \
if (obj.getIs_effective() != -1) { \
	sql << " AND is_effective=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_effective()); \
} \
if (obj.getIs_closed() != -1) { \
	sql << " AND is_closed=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_closed()); \
} \
if (obj.getIs_voided() != -1) {  \
	sql << " AND is_voided=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided()); \
} 

//和PurQuotEntryDO相关的宏
#define PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql) \
SqlParams params;  \
sql << " WHERE 1=1"; \
sql << " AND bill_no=?"; \
SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); 


uint64_t PurQuotDAO::count(const PurQuotDO & iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_quot";
	PUR_QUOT_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
uint64_t PurQuotDAO::count(const PurQuotEntryDO& iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_quot";
	PUR_QUOT_ENTRY_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


//查询单据列表
list<PurQuotDO> PurQuotDAO::selectPurQuotFindBill(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize) {
	stringstream sql;
	sql << "SELECT bill_no, bill_date, subject,src_no,supplier_id,supplier_name, delivery_time,qty,amt,bill_stage, is_effective, is_closed, is_voided, \
	payment_method, delivery_place, contact,phone, fax, email, remark, is_auto, is_rubric, effective_time, approver, create_time, \
	create_by, sys_org_code, update_time, update_by FROM pur_quot";
	PUR_QUOT_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurQuotFindBillMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotDO, PurQuotFindBillMapper>(sqlStr, mapper, params);
}

//报价单列表(多个对象)
list<PurQuotEntryDO> PurQuotDAO::selectPurQuotList(const PurQuotEntryDO& obj) {
	stringstream sql;
	sql << "SELECT src_no, material_id, unit_id, qty, tax_rate, price, discount_rate, \
	amt, remark, custom1, custom2 FROM pur_quot_entry";
	PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql);
	PurQuotListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotEntryDO, PurQuotListMapper>(sqlStr, mapper, params);
}
//报价单分录列表(多个对象)
list<PurQuotEntryDO> PurQuotDAO::selectPurQuotDividedList(const PurQuotEntryDO& obj) {
	stringstream sql;
	sql << "SELECT bill_no, material_id, unit_id, qty, tax_rate, price, \
	amt, remark, custom1, custom2 FROM pur_quot_entry";
	PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql);
	PurQuotDividedListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotEntryDO, PurQuotDividedListMapper>(sqlStr, mapper, params);
}


//查询指定单据的详细信息
list<PurQuotDO> PurQuotDAO::selectPurQuotBase(const PurQuotDO& obj) {
	stringstream sql;
	sql << "SELECT bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided, subject,\
		is_temp_supplied, supplier_id, payment_method, delivery_time, delivery_place, \
	contact, phone, fax, email, remark, approval_mark, attachment, approval_result_type ,\
	 effective_time,approver, bpmi_instance_id, bpmi_instance_id, sys_org_code, create_by, update_time, \
	update_by, is_auto, is_rubric, src_bill_type FROM pur_quot_entry";
	PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql);
	PurQuotBaseMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotDO, PurQuotBaseMapper>(sqlStr, mapper, params);
}
//查询指定单据的详细信息
list<PurQuotEntryDO> PurQuotDAO::selectPurQuotDetail(const PurQuotEntryDO& obj) {
	stringstream sql;
	sql << "SELECT src_no, material_id, unit_id, qty, tax_rate, price, discount_rate,\
		amt, remark, custom1, custom2 FROM pur_quot_entry";
	PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql);
	PurQuotDetailMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotEntryDO, PurQuotDetailMapper>(sqlStr, mapper, params);
}


