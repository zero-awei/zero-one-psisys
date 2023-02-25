#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:37:10

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
#ifndef _PUR_COMPARE_SERVICE_
#define _PUR_COMPARE_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/pur-compare/PurComDetailsVO.h"
#include "../../domain/vo/pur-compare/PurComDividedListVO.h"
#include "../../domain/vo/pur-compare/PurComFindBillVO.h"
#include "../../domain/vo/pur-compare/PurComFindDetailBillVO.h"
#include "../../domain/vo/pur-compare/PurComListVO.h"
#include "../../domain/query/pur-compare/PurComDividedListQuery.h"
#include "../../domain/query/pur-compare/PurComFindBillQuery.h"
#include "../../domain/query/pur-compare/PurComFindDetailBillQuery.h"
#include "../../domain/query/pur-compare/PurComListQuery.h"

//dto
#include "../../domain/dto/pur-compare/AddPurComDTO.h"
#include "../../domain/dto/pur-compare/ModPurComDTO.h"
#include "../../domain/dto/pur-compare/DelPurComDTO.h"
#include "../../domain/dto/pur-compare/PurComModBillStatusDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PurCompareService
{
public:
	// 分页查询比价单单据列表
	PageVO<PurComFindBillVO> listPurComFindBill(const PurComFindBillQuery& query);
	// 查询指定比价单详细信息
	PurComFindDetailBillVO getPurComFindDetailBill(const PurComFindDetailBillQuery& query);
	// 报价单列表
	std::list<PurComListVO> listPurComList(const PurComListQuery& query);
	// 报价单分录列表
	std::list<PurComDividedListVO> listPurComDividedList(const PurComDividedListQuery& query);

	// 保存数据
	uint64_t savePurCom(const AddPurComDTO& dto, PayloadDTO payload);
	// 修改数据
	bool updatePurCom(const ModPurComDTO& dto, PayloadDTO payload);
	// 删除数据
	bool removePurCom(const DelPurComDTO& dto);
	// 修改单据状态
	bool updatePurComBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload);
};

#endif // !_SAMPLE_SERVICE_

