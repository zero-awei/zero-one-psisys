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
#ifndef _PUR_ORDER_SERVICE_
#define _PUR_ORDER_SERVICE_
#include <list>
//#include "FastDfsClient.h"
#include "../../domain/vo/purOrder/PurOrderVO.h"
#include "../../domain/vo/purOrder/PurOrderDetailVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/purOrder/PurOrderQuery.h"
#include "../../domain/dto/purOrder/PurOrderDTO.h"
#include "../../domain/dto/purOrder/PurOrderEntryDTO.h"
#include "../../dao/purOrder/PurOrderDAO.h"
#include "../../dao/purOrder/PurOrderEntryDAO.h"

#include "../../domain/do/PurReq/PurReqDO.h"
#include "../../domain/do/PurReqEntry/PurReqEntryDO.h"
#include "../../domain/do/PurCom/PurComDO.h"
#include "../../domain/do/PurCom/PurComEntryDO.h"
#include "../../domain/do/PurInquiry/PurInquiryDO.h"
#include "../../domain/do/PurInquiry/PurInquiryEntryDO.h"
#include "../../domain/do/PurQuot/PurQuotDO.h"
#include "../../domain/do/PurQuot/PurQuotEntryDO.h"

#include "../../domain/vo/purOrderSub/PurReqEntryVO.h"
#include "../../domain/vo/purOrderSub/PurCompareVO.h"
#include "../../domain/vo/purOrderSub/PurCompareEntryVO.h"
#include "../../domain/vo/purOrderSub/PurInquiryVO.h"
#include "../../domain/vo/purOrderSub/PurInquiryEntryVO.h"
#include "../../domain/vo/purOrderSub/PurQuotVO.h"
#include "../../domain/vo/purOrderSub/PurQuotEntryVO.h"

/**
 * 采购订单服务实现，基础采购订单服务实现
 */
class PurOrderService
{
public:
	// 修改单据状态(关闭/反关闭/作废)
	// 负责人：Andrew
	bool updateStatus(const PurOrderDTO& dto, const PayloadDTO& payload);
	
	// 删除采购订单-ID
	// 负责人：Andrew
	bool removeData(string id);
	// 分页查询所有数据
	PageVO<PurOrderVO> listPurOrder(const PurOrderQuery& query);
	// 查询单个数据
	PurOrderDetailVO getPurOrder(const PurOrderQuery& query);
	// 保存数据
	uint64_t saveData(const PurOrderDTO& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const PurOrderDTO& dto, const PayloadDTO& payload);
};

#endif // !_PUR_ORDER_SERVICE_

