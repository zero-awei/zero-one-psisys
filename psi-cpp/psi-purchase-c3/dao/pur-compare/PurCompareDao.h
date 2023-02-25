#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:54:13

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
#ifndef _PUR_COMPARE_DAO_
#define _PUR_COMPARE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pur-compare/PurCompareDO.h"
#include "../../domain/do/pur-compare/PurCompareEntryDO.h"
#include "../../domain/do/pur-compare/PurComQuotEntryDO.h"
#include "../../domain/do/pur-compare/PurComQuotDO.h"
#include "../../domain/do/pur-compare/AddPurComDO.h"
#include "../../domain/do/pur-compare/ModPurComDO.h"
#include "../../domain/do/pur-compare/DelPurComDO.h"
#include "../../domain/do/pur-compare/PurComModBillStatusDO.h"


/**
 * 示例表数据库操作实现
 */
class PurCompareDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PurCompareDO& iObj);
	// 分页查询比价单单据列表
	list<PurCompareDO> selectPurComFindBill(const PurCompareDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询指定比价单详细信息—比价单
	list<PurCompareDO> selectPurComFindDetailBill(const PurCompareDO& obj);
	// 查询指定比价单详细信息—比价单明细
	list<PurCompareEntryDO> selectPurComFindDetailBillEntry(const PurCompareEntryDO& obj);
	// 查询候选报价单
	list<PurCompareDO> selectCandidateQuot(const PurCompareDO& obj);
	// 查询报价单列表
	list<PurComQuotDO> selectPurComList(const PurCompareDO& obj);
	// 查询报价单分录列表
	list<PurComQuotEntryDO> selectPurComDividedList(const PurComQuotEntryDO& obj);
	// 插入数据
	uint64_t insertPurCom(const AddPurComDO& iObj);
	// 修改数据
	int updatePurCom(const ModPurComDO& uObj);
	// 删除数据
	int deletePurCom(const DelPurComDO& dObj);
	// 修改单据状态
	int updatePurComBillStatus(const ModPurComBillStatusDO& uObj);


};
#endif // !_SAMPLE_DAO_

