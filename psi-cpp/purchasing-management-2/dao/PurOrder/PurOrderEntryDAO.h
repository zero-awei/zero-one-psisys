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
#ifndef _PUR_ORDER_ENTRY_DAO_
#define _PUR_ORDER_ENTRY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"
#include "../../domain/do/PurReq/PurReqDO.h"
#include "../../domain/do/PurReqEntry/PurReqEntryDO.h"
#include "../../domain/do/PurCom/PurComDO.h"
#include "../../domain/do/PurCom/PurComEntryDO.h"
#include "../../domain/do/PurInquiry/PurInquiryDO.h"
#include "../../domain/do/PurInquiry/PurInquiryEntryDO.h"
#include "../../domain/do/PurQuot/PurQuotDO.h"
#include "../../domain/do/PurQuot/PurQuotEntryDO.h"

#include "../PurOrderSub/PurOrderEntryMapper.h"
#include "../PurOrderSub/PurReqMapper.h"
#include "../PurOrderSub/PurReqEntryMapper.h"
#include "../PurOrderSub/PurCompareMapper.h"
#include "../PurOrderSub/PurCompareEntryMapper.h"
#include "../PurOrderSub/PurInquiryMapper.h"
#include "../PurOrderSub/PurInquiryEntryMapper.h"
#include "../PurOrderSub/PurQuotMapper.h"
#include "../PurOrderSub/PurQuotEntryMapper.h"
/**
 * 采购订单表数据库操作实现
 */
class PurOrderEntryDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const PurOrderEntryDO& iObj);
	// 更新数据
	uint64_t update(const PurOrderEntryDO& iObj);
	// 是否存在
	uint64_t count(const PurOrderEntryDO& iObj);

	list<PurReqDO> selectPurReqList();

	list<PurOrderEntryDO> selectPurOrderEntry(const string bill_no);
	list<PurReqDO> selectPurReq(const string id);
	list<PurReqEntryDO> selectPurReqEntry(const string id);
	list<PurComDO> selectPurCompare(const string id);
	list<PurComEntryDO> selectPurCompareEntry(const string id);
	list<PurInquiryDO> selectPurInquiry(const string id);
	list<PurInquiryEntryDO> selectPurInquiryEntry(const string id);
	list<PurQuotDO> selectPurQuot(const string id);
	list<PurQuotEntryDO> selectPurQuotEntry(const string id);
};
#endif // !_PUR_ORDER_DAO_
