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
#include "QtrkDAO.h"
#include <sstream>
#include "../../dao/Cgrk/StkIoMapper.h"
#include "../../dao/Cgrk/StkIoEntryMapper.h"
#include "../../dao/StringMapper.h"

//定义宏
#define BILL_LIST_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1 AND LEFT(bill_no,4)='QTRK' "; \
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
std::list<StkIoDO> QtrkDAO::selectBillList(const QueryQtrkBillListQuery query)
{
	stringstream sql;
	sql << "SELECT * FROM stk_io";
	BILL_LIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query.getPageIndex() - 1) * query.getPageSize()) << "," << query.getPageSize();
	StkIoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<StkIoDO, StkIoMapper>(sqlStr, mapper, params);
}

//查询单个单据列表信息
list<StkIoDO> QtrkDAO::selectBillListByBillNo(string BillNo)
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
list<StkIoEntryDO> QtrkDAO::selectBillDetails(string BillNo)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT * FROM stk_io_entry WHERE bill_no =? ";
	SQLPARAMS_PUSH(params, "s", std::string, BillNo);
	string sqlStr = sql.str();
	StkIoEntryMapper mapper;
	return  sqlSession->executeQuery<StkIoEntryDO, StkIoEntryMapper>(sqlStr, mapper, params);

}

int QtrkDAO::updataBillStatus(const ModifyQtrkBillStatusDO& doObject) {
	string sql = "UPDATE `stk_io` SET `is_closed`=?, `is_voided`=? WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%i%i%s", doObject.getIsClosed(), doObject.getIsVoided(), doObject.getBillNo());
}


int QtrkDAO::deleteBill(const DeleteBill& doObject) {
	string sql = "DELETE from `stk_io` where bill_no = ?";
	return sqlSession->executeUpdate(sql, "%s", doObject.getId());
}