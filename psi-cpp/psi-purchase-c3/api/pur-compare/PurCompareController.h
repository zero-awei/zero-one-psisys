#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:57:54

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
#ifndef _PUR_COMPARE_CONTROLLER_
#define _PUR_COMPARE_CONTROLLER_

#include "../../domain/query/pur-compare/PurComFindBillQuery.h"
#include "../../domain/query/pur-compare/PurComFindDetailBillQuery.h"
#include "../../domain/query/pur-compare/PurComDividedListQuery.h"
#include "../../domain/query/pur-compare/PurComListQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/pur-compare/PurComFindBillVO.h"
#include "../../domain/vo/pur-compare/PurComFindDetailBillVO.h"
#include "../../domain/vo/pur-compare/PurComListVO.h"
#include "../../domain/vo/pur-compare/PurComDividedListVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/sample/SampleDTO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * 比价单控制器
 */
class PurCompareController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindBill, execQueryPurComFindBill, PurComFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindDetailBill, execQueryPurComFindDetailBill, PurComFindDetailBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComList, execQueryPurComList, PurComListQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComDividedList, execQueryPurComDividedList, PurComDividedListQuery);
private:
	// 查询比价单单据列表
	JsonVO<PageVO<PurComFindBillVO>> execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload);
	// 查询指定比价单单据详细信息
	JsonVO<PurComFindDetailBillVO> execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload);
	// 查询报价单列表
	JsonVO<PageVO<PurComListVO>> execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload);
	// 查询报价单分录列表
	JsonVO<PageVO<PurComDividedListVO>> execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload);
};

#endif // _SAMPLE_CONTROLLER_#pragma once
