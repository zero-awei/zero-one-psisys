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
#ifndef _ZDRK_DAO_
#define _ZDRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"
#include "../../domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/dto/Zdrk/AddZdrkBillDTO.h"

/**
 * 涨吨入库数据库操作实现
 */
class ZdrkDAO : public BaseDAO
{
public:
	// 插入数据
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// 审核单据更新数据
	int updateApproval(const StkIoDO& iObj);
	// 修改数据
	int update(const StkIoDO& iObj);
	// 修改单据状态
	int updateState(const StkIoDO& iObj);
	// 更新明细
	int update(const StkIoEntryDO& iObj);
	// 根据单据编号删除单据
	int deleteBillById(const string& billNo);
	// 根据单据编号和分录号删除明细
	int deleteDetailById(const string& billNo, const int& entryNo);
	// 根据单据编号删除所有明细
	int deleteDetailById(const string& billNo); 

	//查询单据列表
	std::list<StkIoDO> selectBillList(const QueryZdrkBillListQuery query);

	//查询单个单据列表信息
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//查询单据详细信息
	list<StkIoEntryDO> selectBillDetails(string billNo);


};
#endif // !_Zdrk_DAO_
