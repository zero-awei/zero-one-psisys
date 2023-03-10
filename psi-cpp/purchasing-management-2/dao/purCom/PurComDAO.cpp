﻿/*
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
#include "PurComDAO.h"
#include "PurComMapper.h"
#include <sstream>

#include "PurOrderDividedListMapper.h"

// 统计数据条数
uint64_t PurComDAO::count(const PurComDO& obj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_compare";
	SqlParams params;
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


// 统计明细条数
uint64_t PurComDAO::countEntrys(const PurComEntryDO& obj) 
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_compare_entry";
	SqlParams params;
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询数据
list<PurComDO> PurComDAO::selectPurCom(const PurComDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	// SQL语句生成
	sql << "SELECT id, bill_no, bill_date, src_bill_type,\
		src_bill_id, src_no, `subject`, is_rubric,\
		candidate_quot_ids, payment_method, delivery_place,\
		delivery_time, attachment, remark, is_auto,\
		bill_stage, approver, bpmi_instance_id,\
		approval_result_type, approval_remark,\
		is_effective, effective_time, is_closed,\
		is_voided, sys_org_code, create_by, create_time,\
		update_by, update_time, version FROM pur_compare";
	SqlParams params;

	sql << " WHERE 1=1";
	// 条件拼接
	if (!obj.getBill_no().empty()) {
		sql << " AND `bill_no`=?";
		params.push_back(SqlParam("s", std::make_shared<std::string>(obj.getBill_no())));
	}

	if (!obj.getSrc_no().empty()) {
		sql << " AND `src_no`=?";
		params.push_back(SqlParam("s", std::make_shared<std::string>(obj.getSrc_no())));
	}

	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurComMapper mapper;
	string sqlStr = sql.str();
	// 结果返回
	return sqlSession->executeQuery<PurComDO, PurComMapper>(sqlStr, mapper, params);
}

// 查询指定比价单明细列表
list<PurComEntryDO> PurComDAO::selectPurComEntry(const PurComEntryDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	// 查询语句生成
	sql << "SELECT id, mid, bill_no, \
			entry_no, src_bill_type, src_bill_id, \
			src_entry_id, src_no, supplier_id, \
			material_id, unit_id, qty, \
			tax_rate, price, discount_rate, \
			amt, ranking, remark, \
			custom1, custom2, version \
			FROM pur_compare_entry";
	SqlParams params;
	// 条件拼接
	sql << " WHERE 1=1";
	if (!obj.getMid().empty()) {
		sql << " AND `mid`=?";
		params.push_back(SqlParam("s", std::make_shared<std::string>(obj.getMid())));
	}

	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurComEntryMapper mapper;
	string sqlStr = sql.str();
	list<PurComEntryDO> temp = sqlSession->executeQuery<PurComEntryDO, PurComEntryMapper>(sqlStr, mapper, params);

	return temp;
}

list<PurOrderDividedListDO> PurComDAO::selectPurOrderDividedListDO(const PurOrderDividedListDO& obj) {
	stringstream sql;
	sql << "SELECT bill_no, entry_no, material_id, unit_id, qty, ordered_qty, tax_rate, price, amt, suggest_supplier_id, remark, custom1, custom2 FROM pur_req_entry";
	SqlParams params;
	sql << " WHERE 1=1 AND bill_no=?";
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo());
	PurOrderDividedListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurOrderDividedListDO, PurOrderDividedListMapper>(sqlStr, mapper, params);
}