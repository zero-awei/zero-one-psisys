
#include "stdafx.h"
#include "PurOrderDAO.h"
#include <sstream>
//mapper
#include "PurOrderDividedListMapper.h"

//采购申请单分录列表
list<PurOrderDividedListDO> PurOrderDAO::selectPurOrderDividedListDO(const PurOrderDividedListDO& obj) {
	stringstream sql;
	sql << "SELECT 	bill_no, entry_no, material_id, unit_id, qty, ordered_qty,\
	tax_rate, price, amt, suggest_supplier_id, remark, custom1, custom2  FROM pur_order_entry";
	SqlParams params;  
	sql << " WHERE 1=1 AND bill_no=?"; 
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo()); 
	PurOrderDividedListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurOrderDividedListDO, PurOrderDividedListMapper>(sqlStr, mapper, params);
}