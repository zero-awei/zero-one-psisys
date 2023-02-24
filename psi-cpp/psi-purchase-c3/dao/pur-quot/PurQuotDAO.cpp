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


//查询指定单据的详细信息---pur_quot表
list<PurQuotDO> PurQuotDAO::selectPurQuotBase(const PurQuotDO& obj) {
	stringstream sql;
	sql << "SELECT bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided, subject,\
		is_temp_supplied, supplier_id, payment_method, delivery_time, delivery_place, \
	contact, phone, fax, email, remark, approval_mark, attachment, approval_result_type ,\
	 effective_time,approver, bpmi_instance_id, bpmi_instance_id, sys_org_code, create_by, update_time, \
	update_by, is_auto, is_rubric, src_bill_type FROM pur_quot";
	PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql);
	PurQuotBaseMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotDO, PurQuotBaseMapper>(sqlStr, mapper, params);
}
//查询指定单据的详细信息----pur_quot_entry表
list<PurQuotEntryDO> PurQuotDAO::selectPurQuotDetail(const PurQuotEntryDO& obj) {
	stringstream sql;
	sql << "SELECT src_no, material_id, unit_id, qty, tax_rate, price, discount_rate,\
		amt, remark, custom1, custom2 FROM pur_quot_entry";
	PUR_QUOT_ENTRY_TERAM_PARSE(obj, sql);
	PurQuotDetailMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurQuotEntryDO, PurQuotDetailMapper>(sqlStr, mapper, params);
}





//拼接sql语句，插入操作
uint64_t PurQuotDAO::insert(const PurQuotNaiGuanDO& iObj)
{
	//在分录表pur_quot_entry中，新增供应报价明细中的数据
	for (PurQuotDetailDTO Add : iObj.getDetail()) {
		string sqlEntry = "INSERT INTO `pur_quot_entry` (\
`id`, `mid`, `bill_no`, `entry_no`, \
`src_bill_type`, `src_bill_id`, `src_entry_id`, `src_no`, \
`material_id`, `unit_id`, `qty`, `tax_rate`, \
`price`, `discount_rate`, `amt`,`remark`, \
`custom1`, `custom2`, `version`) \
VALUES (?, ?, ?, ?, \
? , ? , ? , ? , \
?, ?, ?, ?, \
?, ?, ?, ?, \
?, ?, ?)";
		sqlSession->executeUpdate(sqlEntry, "%s%s%s%i\
%s%s%s%s\
%s%s%d%d\
%d%d%d%s\
%s%s%i",
Add.getId(), Add.getMid(), iObj.getBillNo(), Add.getEntry_no(),
Add.getSrc_bill_type(), Add.getSrc_bill_type(), Add.getSrc_entry_id(), Add.getSrc_no(),
Add.getMaterial_id(), Add.getUnit_id(), Add.getQty(), Add.getTax_rate(),
Add.getPrice(), Add.getDiscount_rate(), Add.getAmt(), Add.getRemark(),
Add.getCustom1(), Add.getCustom2(), Add.getVersion());
	}
	//在pur_quot中，新增供应报价数据
	string sql = "INSERT INTO `pur_quot` (\
`id`, `bill_no`, `bill_date`, `src_bill_type`, \
`src_bill_id`, `src_no`, `subject`, `is_rubric`, \
`is_temp_supplier`, `supplier_id`, `supplier_name`, `payment_method`, \
`delivery_time`, `delivery_place`, `contact`, `phone`, \
`fax`, `email`, `qty`, `amt`, \
`attachment`, `remark`, `is_auto`, `bill_stage`, \
`approver`, `bpmi_instance_id`, `approval_result_type`, `approval_remark`, \
`is_effective`, `effective_time`, `is_closed`, `is_voided`, \
`sys_org_code`, `create_by`, `create_time`, `update_by`, \
`update_time`, `version`) \
VALUES (? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s\
%s%s%s%i\
%i%s%s%s\
%s%s%s%s\
%s%s%d%d\
%s%s%i%s\
%s%s%s%s\
%i%s%i%i\
%s%s%s%s\
%s%i",
iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSrcBillType(),
iObj.getSrcBillId(), iObj.getSrcNo(), iObj.getSubject(), iObj.getIsRubric(),
iObj.getIsTempSupplier(), iObj.getSupplierId(), iObj.getTempSupplierName(), iObj.getDeliveryMethod(),
iObj.getDeliveryDate(), iObj.getDeliveryAddress(), iObj.getContact(), iObj.getPhone(),
iObj.getFax(), iObj.getEmail(), iObj.getQty(), iObj.getAmt(),
iObj.getAttachment(), iObj.getRemark(), iObj.getIsAuto(), iObj.getBillStage(),
iObj.getApprover(), iObj.getBpmi_instance_id(), iObj.getApprovalResultType(), iObj.getApprovalRemark(),
iObj.getIsEffective(), iObj.getEffectiveTime(), iObj.getIsClosed(), iObj.getIsVoided(),
iObj.getSysOrdCode(), iObj.getCreateBy(), iObj.getCreateTime(), iObj.getUpdateBy(),
iObj.getUpdateTime(), iObj.getVersion());
}

//拼接sql语句，修改操作
int PurQuotDAO::update(const PurQuotNaiGuanDO& uObj)
{

	//删除全部已有的明细数据
	std::cout << uObj.getBillNo() << endl;
	string sqlClear = "DELETE FROM `pur_quot_entry` WHERE `bill_no`=?";
	sqlSession->executeUpdate(sqlClear, "%s", uObj.getBillNo());

	//重新插入所有明细数据
	for (PurQuotDetailDTO Add : uObj.getDetail()) {
		std::cout << Add.getId() << endl;

		string sqlEntry = "INSERT INTO `pur_quot_entry` (\
`id`, `mid`, `bill_no`, `entry_no`, \
`src_bill_type`, `src_bill_id`, `src_entry_id`, `src_no`, \
`material_id`, `unit_id`, `qty`, `tax_rate`, \
`price`, `discount_rate`, `amt`,`remark`, \
`custom1`, `custom2`, `version`) \
VALUES (\
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ? , ? , \
? , ? , ?)";
		sqlSession->executeUpdate(sqlEntry, "%s%s%s%i%s%s%s%s%s%s%d%d%d%d%d%s%s%s%i",
			Add.getId(), Add.getMid(), uObj.getBillNo(), Add.getEntry_no(),
			Add.getSrc_bill_type(), Add.getSrc_bill_type(), Add.getSrc_entry_id(), Add.getSrc_no(),
			Add.getMaterial_id(), Add.getUnit_id(), Add.getQty(), Add.getTax_rate(),
			Add.getPrice(), Add.getDiscount_rate(), Add.getAmt(), Add.getRemark(),
			Add.getCustom1(), Add.getCustom2(), Add.getVersion());

	}

	string sql = "UPDATE `pur_quot` SET\
`bill_date`=?, `src_bill_type`=?, \
`src_bill_id`=?, `src_no`=?, `subject`=?, `is_rubric`=?, \
`is_temp_supplier`=?, `supplier_id`=?, `supplier_name`=?, `payment_method`=?, \
`delivery_time`=?, `delivery_place`=?, `contact`=?, `phone`=?, \
`fax`=?, `email`=?, `qty`=?, `amt`=?, \
`attachment`=?, `remark`=?, `is_auto`=?, `bill_stage`=?, \
`approver`=?, `bpmi_instance_id`=?, `approval_result_type`=?, `approval_remark`=?, \
`is_effective`=?, `effective_time`=?, `is_closed`=?, `is_voided`=?, \
`sys_org_code`=?, `update_by`=?, \
`update_time`=?, `version`=? \
WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%s%s\
%s%s%s%i\
%i%s%s%s\
%s%s%s%s\
%s%s%d%d\
%s%s%i%s\
%s%s%s%s\
%i%s%i%i\
%s%s%s%i\
%s",
uObj.getBillDate(), uObj.getSrcBillType(),
uObj.getSrcBillId(), uObj.getSrcNo(), uObj.getSubject(), uObj.getIsRubric(),
uObj.getIsTempSupplier(), uObj.getSupplierId(), uObj.getTempSupplierName(), uObj.getDeliveryMethod(),
uObj.getDeliveryDate(), uObj.getDeliveryAddress(), uObj.getContact(), uObj.getPhone(),
uObj.getFax(), uObj.getEmail(), uObj.getQty(), uObj.getAmt(),
uObj.getAttachment(), uObj.getRemark(), uObj.getIsAuto(), uObj.getBillStage(),
uObj.getApprover(), uObj.getBpmi_instance_id(), uObj.getApprovalResultType(), uObj.getApprovalRemark(),
uObj.getIsEffective(), uObj.getEffectiveTime(), uObj.getIsClosed(), uObj.getIsVoided(),
uObj.getSysOrdCode(), uObj.getUpdateBy(), uObj.getUpdateTime(), uObj.getVersion(),
uObj.getBillNo());

}


//拼接sql语句，通过id查询操作
int PurQuotDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `pur_quot` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

//拼接sql语句，通过bill_no删除数据
int PurQuotDAO::deleteByBillNo(const PurQuotNaiGuanDO& dObj)
{
	//删除供应报价分录pur_quot_entry数据
	string sqlClearEntry = "DELETE FROM `pur_quot_entry` WHERE `bill_no`=?";
	sqlSession->executeUpdate(sqlClearEntry, "%s", dObj.getBillNo());
	//删除供应报价目录pur_quot数据
	string sqlClear = "DELETE FROM `pur_quot` WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sqlClear, "%s", dObj.getBillNo());
}

//拼接sql语句，通过bill_no修改报价状态
int PurQuotDAO::updateBillStatus(const PurQuotNaiGuanDO& ubsObj)
{
	//修改报价状态
	string sql = "UPDATE `pur_quot` SET `is_effective`=?, `effective_time`=?, `is_closed`=?, `is_voided`=?, `approval_result_type`=?, `approval_remark`=?, `bill_stage`=?, `approver`=? WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%i%s%i%i%s%s%s%s%s",
		ubsObj.getIsEffective(), ubsObj.getEffectiveTime(), ubsObj.getIsClosed(), ubsObj.getIsVoided(),
		ubsObj.getApprovalResultType(), ubsObj.getApprovalRemark(), ubsObj.getBillStage(), ubsObj.getApprover(),
		ubsObj.getBillNo());
}