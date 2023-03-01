#include "stdafx.h"
#include "PrepaymentDAO.h"
#include "PrepaymentMapper.h"
#include "PrepaymentDetailMapper.h"
#include <sstream>

//付款申请单-fin_payment_req
//定义条件解析宏，减少重复代码
#define JUDGE_STRING_SQL(sobj,ssql,sparams,funName,lowName)\
if(!##sobj.get##funName().empty()){ \
    ssql << "AND `"#lowName"`=?";\
    SQLPARAMS_PUSH(sparams, "s", std::string, sobj.get##funName()); \
}
#define JUDGE_INT_SQL(sobj,ssql,sparams,funName,lowName)\
if(sobj.get##funName() != -1){ \
    ssql << "AND `"#lowName"`=?";\
    SQLPARAMS_PUSH(sparams, "i", int, sobj.get##funName()); \
}
#define JUDGE_DATE_SQL(sobj,ssql,sparams,dataName,funName1,funName2)\
if(!##sobj.get##funName1().empty()){ \
    ssql << "AND `"#dataName"` >=?";\
    SQLPARAMS_PUSH(sparams, "s", std::string, sobj.get##funName1()); \
}\
if(!##sobj.get##funName2().empty()){ \
    ssql << "AND `"#dataName"` <=?";\
    SQLPARAMS_PUSH(sparams, "s", std::string, sobj.get##funName2()); \
}\

#define PREPAYMENT_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1 "; \
JUDGE_STRING_SQL(obj,sql,params,Bill_no, bill_no)\
JUDGE_DATE_SQL(obj,sql,params,bill_data,Bill_begin_date, Bill_end_date)\
JUDGE_STRING_SQL(obj,sql,params,Subject, subject)\
JUDGE_STRING_SQL(obj,sql,params,Supplier_id, supplier_id)\
JUDGE_STRING_SQL(obj,sql,params,Bill_stage, bill_stage)\
JUDGE_INT_SQL(obj,sql,params,Is_effective, is_effective)\
JUDGE_INT_SQL(obj,sql,params,Is_closed, is_closed)\
JUDGE_INT_SQL(obj,sql,params,Is_voided, is_voided)\






#define MODIFT_TYPE 
#define MODIFT_DETAIL_LIST "(`bill_no`,`entry_no`,`src_bill_type`,\
`src_bill_id`,`src_entry_id`,`src_no`,`amt`,`paid_amt`,\
`remark`,`custom1`,`custom2`)"
#define MODIFT_DETAIL_TYPE "%s%s%s\
%s%s%s%s%s\
%s%s%s%s"



//`approval_result_type`,`approval_remark` `update_by`,\
`update_time`"
std::string ValueNum(unsigned int x) {
	std::string str;
	while (x-- > 1) {
		str.push_back('?');
		str.push_back(',');	
	}
	str.push_back('?');
	return str;
}



//页数统计
uint64_t PrepaymentDAO::count(const PrepaymentDO & iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_payment_req";
	PREPAYMENT_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//明细条数统计
uint64_t PrepaymentDAO::countDetail(const PrepaymentDetailDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_payment_req_entry WHERE `bill_no` = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, iObj.getBill_no());
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//查询单据信息
std::list<PrepaymentDO> PrepaymentDAO::selectWithPage(const PrepaymentDO & obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM fin_payment_req";
	PREPAYMENT_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PrepaymentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PrepaymentDO, PrepaymentMapper>(sqlStr, mapper, params);
}
//查询指定单据详细信息
std::list <PrepaymentDetailDO> PrepaymentDAO::selectByBill_no(const string& bill_no)
{
	stringstream sql;
	sql << "SELECT * FROM fin_payment_req_entry WHERE `bill_no` = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, bill_no);
	PrepaymentDetailMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PrepaymentDetailDO, PrepaymentDetailMapper>(sqlStr, mapper, params);
}
//新增预付申请单
uint64_t PrepaymentDAO::insertPrepay(const PrepaymentDO& iObj)
{
	uint64_t result;
	stringstream sql;
	sql << "INSERT INTO `fin_payment_req` (" 
		<< "`id`,`bill_no`,`bill_date`, `src_bill_type`,`src_bill_id`,"
		<< "`src_no`,`subject`,`payment_type`,`supplier_id`,`op_dept`,"
		<< "`operator`,`amt`,`paid_amt`,`attachment`,`remark`," 
		<< "`is_auto`,`bill_stage`,`sys_org_code`,`create_by`,`create_time`"
		<< ") VALUES ("<< ValueNum(19)<<",NOW())";
	string sqlStr = sql.str();
	result = sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%s%s%s%s%s%s%d%d%s%s%i%s%s%s",
		iObj.getId(),iObj.getBill_no(), iObj.getBill_begin_date(), iObj.getSrc_bill_type(), iObj.getSrc_bill_id(), 
		iObj.getSrc_no(),iObj.getSubject(), iObj.getPayment_type(), iObj.getSupplier_id(), iObj.getOp_dept(), 
		iObj.getOperator(),iObj.getAmt(), iObj.getPaid_amt(), iObj.getAttachment(), iObj.getRemark(), 
		iObj.getIs_auto(),iObj.getBill_stage(), iObj.getSys_org_code(), iObj.getCreate_by()
	);
	sql.clear();
	sql.str("");
	sql << "INSERT INTO `fin_payment_req_entry` "
		<< "(`id`,`mid`,`bill_no`,`entry_no`,`src_bill_type`,"
		<< "`src_bill_id`,`src_entry_id`,`src_no`,`amt`,`paid_amt`,"
		<< "`remark`,`custom1`,`custom2`)"
		<< " VALUES (" << ValueNum(13) << ")";
	sqlStr = sql.str();
	for (PrepaymentDetailDO dtObj : iObj.getDetail()) {
		sqlSession->executeUpdate(sqlStr, "%s%s%s%i%s%s%s%s%d%d%s%s%s",
			dtObj.getId(), dtObj.getMid(), dtObj.getBill_no(), dtObj.getEntry_no(), dtObj.getSrc_bill_type(), 
			dtObj.getSrc_bill_id(),dtObj.getSrc_entry_id(), dtObj.getSrc_no(), dtObj.getAmt(), dtObj.getPaid_amt(), 
			dtObj.getRemark(),dtObj.getCustom1(), dtObj.getCustom2()
		);
	}
	return result;
}

//修改预付申请单
/*
	（1）接受前端传来的id,对比主表并修改对应的内容
	（2）删除所有明细表中Mid和前端传来的ID一样的
	（3）重新插入对应的新的明细表
*/
int PrepaymentDAO::updatePrepay(const PrepaymentDO& uObj)
{
	stringstream sql;
	sql << "UPDATE `fin_payment_req` SET " 
		<< "`bill_date`=?, `src_bill_type`=?,`src_bill_id`=?,`src_no`=?,`subject`=?,"
		<< "`supplier_id`=?,`op_dept`=?,`operator`=?,`amt`=?,`paid_amt`=?,"
		<< "`attachment`=?,`remark`=?,`update_by`=?,"
        << "`update_time`=NOW() WHERE `id`=?";
	string sqlStr = sql.str();
	int result;
	result = sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%s%s%s%d%d%s%s%s%s",
		uObj.getBill_begin_date(), uObj.getSrc_bill_type(), uObj.getSrc_bill_id(), uObj.getSrc_no(),
		uObj.getSubject(), uObj.getSupplier_id(), uObj.getOp_dept(), uObj.getOperator(), uObj.getAmt(),
		uObj.getPaid_amt(), uObj.getAttachment(), uObj.getRemark(), uObj.getUpdate_by(), uObj.getId()
	); 
	//清除明细
	sql.clear();
	sql.str("");
	sql << "DELETE FROM `fin_payment_req_entry` WHERE `mid`= ? ";
	sqlStr = sql.str();
	sqlSession->executeUpdate(sqlStr, "%s", uObj.getId());
	//插入明细
	sql.clear();
	sql.str("");
	sql << "INSERT INTO `fin_payment_req_entry` "
		<< "(`id`,`mid`,`bill_no`,`entry_no`,`src_bill_type`,"
		<< "`src_bill_id`,`src_entry_id`,`src_no`,`amt`,`paid_amt`,"
		<< "`remark`,`custom1`,`custom2`)"
		<< " VALUES (" << ValueNum(13) << ")";
	sqlStr = sql.str();
	bool flag = false;
	for (PrepaymentDetailDO dtObj : uObj.getDetail()) {
		uint64_t result_detail = sqlSession->executeUpdate(sqlStr, "%s%s%s%i%s%s%s%s%d%d%s%s%s",
			dtObj.getId(), dtObj.getMid(), dtObj.getBill_no(), dtObj.getEntry_no(), dtObj.getSrc_bill_type(),
			dtObj.getSrc_bill_id(), dtObj.getSrc_entry_id(), dtObj.getSrc_no(), dtObj.getAmt(), dtObj.getPaid_amt(),
			dtObj.getRemark(), dtObj.getCustom1(), dtObj.getCustom2()
		);
		if (result_detail != 0 && !flag) {
			flag = true;
		}
	}
	if (flag == true || result != 0);
	return result;
}


//修改单据状态
int PrepaymentDAO::updateStatus(const PrepaymentDO& uObj)
{
	string sql = "UPDATE `fin_payment_req` SET `bill_no`=?, `is_effective`=?, `effective_time`=?,`is_closed`=?,`is_voided`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%i%s%i%i%ull", uObj.getBill_no(), uObj.getIs_effective(), uObj.getEffective_time(), uObj.getIs_closed(), uObj.getIs_voided(), uObj.getId());
}

// 删除预付申请单
int PrepaymentDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

// 保存导入数据
uint64_t PrepaymentDAO::insertInfo(const PrepaymentDO& iObj)
{
	return 1;
//	string sql = "INSERT INTO `fin_payment_req` (`bill_no`, `bill_date`, `amt`) VALUES (?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getBill_no(), iObj.getBill_date(), iObj.getAmt());
}