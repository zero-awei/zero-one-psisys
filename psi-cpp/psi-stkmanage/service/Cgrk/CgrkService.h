#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#include <list>
#include "../../domain/query/Cgrk/QueryCgrkBillListQuery.h"
#include "../../domain/query/Cgrk/QueryCgrkBillListAdvancedQuery.h"
#include "../../domain/query/Cgrk/QueryCgrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Cgrk/QueryCgrkBillListVO.h"
#include "../../domain/vo/Cgrk/QueryCgrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/Cgrk/AddCgrkBillDTO.h"
#include "../../domain/dto/Cgrk/ModifyCgrkBillDTO.h"
#include "../../domain/dto/Cgrk/ModifyCgrkBillStateDTO.h"
#include "../../domain/dto/Cgrk/RemoveCgrkBillDTO.h"
#include "../../domain/dto/Cgrk/ImportCgrkFileDTO.h"
#include "../../domain/query/Cgrk/QueryPurOrderListQuery.h"
#include "../../domain/vo/Cgrk/QueryPurOrderListVO.h"
#include "../../domain/query/Cgrk/QueryPurOrderEntryQuery.h"
#include "../../domain/vo/Cgrk/QueryPurOrderEntryVO.h"
#include "../../domain/vo/Cgrk/QueryPurOrderEntryListVO.h"
#include"../../domain/dto/Cgrk/ModifyCgrkBillStateDTO.h"

#ifndef CGRK_SERVERICE
#define CGRK_SERVERICE
/**
 * 采购入库服务实现
 */
class CgrkService
{
public:
	// 分页查询所有数据
	PageVO<QueryCgrkBillListVO> listCgrkBillList(const QueryCgrkBillListQuery& query);

	//高级分页查询数据
	PageVO<QueryCgrkBillListVO>  listCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query);

	//查询单据详细信息
	QueryCgrkBillDetailsVO getCgrkBillDetails(const QueryCgrkBillDetailsQuery& query);


	//查询采购订单列表
	PageVO<QueryPurOrderListVO> listPurOrderList(const QueryPurOrderListQuery& query);
	
	//采购订单分录列表
	PageVO<QueryPurOrderEntryVO> listPurOrderEntry(const QueryPurOrderEntryQuery& query);

	//添加采购入库单
	int saveCgrkBill(const AddCgrkBillDTO& dto, const PayloadDTO& payload);

	//修改采购入库单
	int updateCgrkBill(const ModifyCgrkBillDTO dto, const PayloadDTO& payload);

	//删除采购入库单
	bool removeCgrkBill(string id);

	//修改单据状态
	bool updataBillStatus(const ModifyCgrkBillStateDTO& dto);
};


#endif // !CGRK_SERVERICE

