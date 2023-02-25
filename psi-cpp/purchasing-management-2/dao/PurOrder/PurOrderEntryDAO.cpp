/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/25 14:26:52

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
#include "PurOrderEntryDAO.h"
#include "PurOrderMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PUR_ORDER_ENTRY_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getId().empty()) { \
    sql << " AND `id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
} \
if (!obj.getMid().empty()) { \
    sql << " AND `mid`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getMid()); \
} \
if (!obj.getBill_no().empty()) { \
    sql << " AND `bill_no`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getEntry_no()) { \
    sql << " AND `entry_no`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getEntry_no()); \
} \
if (!obj.getSrc_bill_type().empty()) { \
    sql << " AND `src_bill_type`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_bill_type()); \
} \
if (!obj.getSrc_bill_id().empty()) { \
    sql << " AND `src_bill_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_bill_id()); \
} \
if (!obj.getSrc_entry_id().empty()) { \
    sql << " AND `src_entry_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_entry_id()); \
} \
if (!obj.getSrc_no().empty()) { \
    sql << " AND `src_no`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getSrc_no()); \
} \
if (!obj.getMaterial_id().empty()) { \
    sql << " AND `material_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getMaterial_id()); \
} \
if (!obj.getUnit_id().empty()) { \
    sql << " AND `unit_id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getUnit_id()); \
} \
if (!obj.getQty()) { \
    sql << " AND `qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getQty()); \
} \
if (!obj.getTax_rate()) { \
    sql << " AND `tax_rate`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getTax_rate()); \
} \
if (!obj.getPrice()) { \
    sql << " AND `price`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getPrice()); \
} \
if (!obj.getDiscount_rate()) { \
    sql << " AND `discount_rate`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getDiscount_rate()); \
} \
if (!obj.getTax()) { \
    sql << " AND `tax`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getTax()); \
} \
if (!obj.getAmt()) { \
    sql << " AND `amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getAmt()); \
} \
if (!obj.getIn_qty()) { \
    sql << " AND `in_qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIn_qty()); \
} \
if (!obj.getIn_cost()) { \
    sql << " AND `in_cost`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getIn_cost()); \
} \
if (!obj.getSettle_qty()) { \
    sql << " AND `settle_qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettle_qty()); \
} \
if (!obj.getSettle_amt()) { \
    sql << " AND `settle_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getSettle_amt()); \
} \
if (!obj.getInvoiced_qty()) { \
    sql << " AND `invoiced_qty`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getInvoiced_qty()); \
} \
if (!obj.getInvoiced_amt()) { \
    sql << " AND `invoiced_amt`=?"; \
    SQLPARAMS_PUSH(params, "d", double, obj.getInvoiced_amt()); \
} \
if (!obj.getRemark().empty()) { \
    sql << " AND `remark`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getRemark()); \
} \
if (!obj.getCustom1().empty()) { \
    sql << " AND `custom1`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getCustom1()); \
} \
if (!obj.getCustom2().empty()) { \
    sql << " AND `custom2`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, obj.getCustom2()); \
} \
if (!obj.getVersion()) { \
    sql << " AND `version`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getVersion()); \
}
// 插入数据
uint64_t PurOrderEntryDAO::insert(const PurOrderEntryDO& iObj)
{
    string sql = "INSERT INTO `pur_order_entry` (id,mid,bill_no,entry_no,src_bill_type,src_bill_id,src_entry_id,src_no,material_id,unit_id,qty,tax_rate,price,discount_rate,tax,amt,in_qty,in_cost,settle_qty,settle_amt,invoiced_qty,invoiced_amt,remark,custom1,custom2,version) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    return sqlSession->executeInsert(sql, "%s%s%s%i%s%s%s%s%s%s%d%d%d%d%d%d%d%d%d%d%d%d%s%s%s%i", iObj.getId(), iObj.getMid(), iObj.getBill_no(), iObj.getEntry_no(), iObj.getSrc_bill_type(), iObj.getSrc_bill_id(), iObj.getSrc_entry_id(), iObj.getSrc_no(), iObj.getMaterial_id(), iObj.getUnit_id(), iObj.getQty(), iObj.getTax_rate(), iObj.getPrice(), iObj.getDiscount_rate(), iObj.getTax(), iObj.getAmt(), iObj.getIn_qty(), iObj.getIn_cost(), iObj.getSettle_qty(), iObj.getSettle_amt(), iObj.getInvoiced_qty(), iObj.getInvoiced_amt(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2(), iObj.getVersion());
}

// 更新数据
uint64_t PurOrderEntryDAO::update(const PurOrderEntryDO& iObj)
{
    return 0;
}

// 是否存在
uint64_t PurOrderEntryDAO::count(const PurOrderEntryDO& iObj)
{
    stringstream sql;
    sql <<  "SELECT count(*) FROM `pur_order_entry`";
    PUR_ORDER_ENTRY_TERAM_PARSE(iObj, sql);
    string sqlstr = sql.str();
    return sqlSession->executeQueryNumerical(sqlstr, params);
}