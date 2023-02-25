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
#include "PurOrderDAO.h"
#include "PurOrderMapper.h"
#include <sstream>

#define PUR_ORDER_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
    sql << " AND `bill_no`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getBill_date().empty()) { \
    sql << " AND `bill_date`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
} \
if (!obj.getSubject().empty()) { \
    sql << " AND `subject`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (!obj.getSupplier_id().empty()) { \
    sql << " AND `supplier_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSupplier_id()); \
} \
if (!obj.getOp_er().empty()) { \
    sql << " AND `operator`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getOp_er()); \
} \
if (!obj.getBill_stage().empty()) { \
    sql << " AND `bill_stage`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_stage()); \
} \
if (obj.getIs_effective()!=-1) { \
    sql << " AND `is_effective`=?"; \
    SQLPARAMS_PUSH(params, "i",int, obj.getIs_effective()); \
} \
if (obj.getIs_closed()!=-1) { \
    sql << " AND `is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIs_closed()); \
} \
if (obj.getIs_voided()!=-1) { \
    sql << " AND `is_voided`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided()); \
} 


uint64_t PurOrderDAO::count(const PurOrderDO& iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_order";
    PUR_ORDER_TERAM_PARSE(iObj, sql);

	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);

}
std::list<PurOrderDO> PurOrderDAO::selectWithPage(const PurOrderDO& jobj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM pur_order";
    PUR_ORDER_TERAM_PARSE(jobj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurOrderMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurOrderDO, PurOrderMapper>(sqlStr, mapper, params);
}