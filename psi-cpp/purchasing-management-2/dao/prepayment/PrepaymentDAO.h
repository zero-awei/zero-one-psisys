#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2022/10/25 11:08:56

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
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderDO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"
#include "../../domain/do/prepayment/PrepaymentDetailDO.h"

/**
 *  采购订单列表,采购订单分录列表,删除采购预付申请单
 */
class PrepaymentDAO : public BaseDAO
{
public:
	// 统计数据条数
	// 负责人: Qi
	uint64_t count(const PrepaymentDO& iObj);
	// 统计详情数据条数
	// 负责人: Qi
	uint64_t countDetail(const PrepaymentDetailDO& iObj);
	// 查询指定单据详细信息-通过单据编号查询数据
	// 负责人: Qi
	list<PrepaymentDetailDO> selectByBill_no(const string& bill_no);
	// 添加预付申请单数据
	// 负责人: Qi
	uint64_t insertPrepay(const PrepaymentDO& iObj);
	// 修改预付申请单数据
	// 负责人: Qi
	int updatePrepay(const PrepaymentDO& uObj);
	//分页查询预付申请单列表
	// 负责人: Qi
	list<PrepaymentDO> selectWithPage(const PrepaymentDO& obj, uint64_t pageIndex, uint64_t pageSize);
	
	// 修改单据状态(关闭/反关闭/作废)
	// 负责人：Andrew
	int updateStatusClose(const PrepaymentDO& uObj);
	int updateStatusCancel(const PrepaymentDO& uObj);
	
	// 分页查询数据
	// 负责人：徐不洗
	list<PurOrderDO> selectWithPage(const PurOrderDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 统计数据条数
	// 负责人：徐不洗
	uint64_t count(const PurOrderDO& iObj);
	list<PurOrderDO> selectByBill_no(const PurOrderDO& obj);
	// 通过ID删除数据
	// 负责人：徐不洗
	int deleteById(const PrepaymentDO& uObj);
};
#endif // !_PREPAYMENT_DAO_