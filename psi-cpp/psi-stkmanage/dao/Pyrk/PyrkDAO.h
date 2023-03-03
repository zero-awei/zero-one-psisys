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
#ifndef _PYRK_DAO_
#define _PYRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"

#include "../../domain/vo/Pyrk/QueryPyrkBillDetailsVO.h"
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"


/**
 * 采购入库数据库操作实现
 */
class PyrkDAO : public BaseDAO
{
public:

	//查询单据列表
	std::list<StkIoDO> selectBillList(const QueryPyrkBillListQuery query);

	//查询单个单据列表信息
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//查询单据详细信息
	list<StkIoEntryDO> selectBillDetails(string billNo);



};
#endif // !_SAMPLE_DAO_
