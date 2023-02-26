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
#include "../../domain/dto/Cgrk/AddCgrkBillDTO.h"

/**
 * 采购入库数据库操作实现
 */
class CgrkDAO : public BaseDAO
{
public:
	//查询数据总条数
		// 统计数据条数
	uint64_t count(const StkIoDO& iObj);


	//查询单据列表
	std::list<StkIoDO> selectBillList(const QueryCgrkBillListQuery query);

	//查询单个单据列表信息
	list<StkIoDO>selectBillListByBillNo(string BillNo);


	//查询单据详细信息
	list<StkIoEntryDO> selectBillDetails(string billNo);

	//查询采购订单信息
	list<PurOrderDO> selectPurOrderList(const QueryPurOrderListQuery& query);

	//查询采购订单分录列表
	list<PurOrderEntryDO> selectPurOrderEntry(const QueryPurOrderEntryQuery& query);

	//添加采购入库单
	uint64_t insertCgrkBill(const AddCgrkBillDTO& obj);

	//删除采购入库单
	uint64_t deleteCgrkBill(string id);

	//// 统计数据条数
	//uint64_t count(const SampleDO& iObj);
	//// 分页查询数据
	//list<SampleDO> selectWithPage(const SampleDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//// 通过姓名查询数据
	//list<SampleDO> selectByName(const string& name);
	//// 插入数据
	//uint64_t insert(const SampleDO& iObj);
	//// 修改数据
	//int update(const SampleDO& uObj);
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
