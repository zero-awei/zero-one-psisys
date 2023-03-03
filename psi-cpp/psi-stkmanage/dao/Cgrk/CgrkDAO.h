#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _CGRK_DAO_
#define _CGRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/do/Cgrk/PurOrderDO.h"
#include "../../domain/do/Cgrk/PurOrderEntryDO.h"
#include "../../domain/vo/Cgrk/QueryCgrkBillDetailsVO.h"
#include "../../domain/query/Cgrk/QueryCgrkBillListQuery.h"
#include "../../domain/query/Cgrk/QueryPurOrderListQuery.h"
#include "../../domain/query/Cgrk/QueryPurOrderEntryQuery.h"
#include "../../domain/query/Cgrk/QueryCgrkBillListAdvancedQuery.h"
#include "../../domain/dto/Cgrk/AddCgrkBillDTO.h"

/**
 * 采购入库数据库操作实现
 */
class CgrkDAO : public BaseDAO
{
public:

	//查询单据列表
	std::list<StkIoDO> selectBillList(const QueryCgrkBillListQuery query);

	//高级查询单据列表
	std::list<StkIoDO> selectBillListAnvanced(const QueryCgrkBillListAdvancedQuery& query);

	//查询单个单据列表信息
	list<StkIoDO>selectBillListByBillNo(string BillNo);


	//查询单据详细信息
	list<StkIoEntryDO> selectBillDetails(string billNo);

	//查询采购订单信息
	list<PurOrderDO> selectPurOrderList(const QueryPurOrderListQuery& query);

	//查询采购订单分录列表
	list<PurOrderEntryDO> selectPurOrderEntry(const QueryPurOrderEntryQuery& query);

	//添加采购入库单
	int insertCgrkBill(const StkIoDO& iObj);

	//添加采购入库单明细
	int insertCgrkBillEntry(const StkIoEntryDO& iObj);

	//通过源单号查询源单id
	string selectSrcBillIdBySrcNo(const string& srcNo);
	//通过源单号查询源单类型
	string selectSrcBillTypeBySrcNo(const string& srcNo);
	//查询用户部门
	string selectOpDeptById(const string& id);
	//查询单据id
	string selectIdBySrcNo(const string& srcNo);

	//修改采购入库单
	int updateCgrkBill(const StkIoDO& iObj);
	//删除采购入库单明细
	int deleteCgrkBillEntry(const string& billNo);

	//删除采购入库单
	uint64_t deleteCgrkBill(const string& id);


};
#endif // !_SAMPLE_DAO_
