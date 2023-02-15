#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _ENTRY_PUR_INQUIRY_DTO_
#define _ENTRY_PUR_INQUIRY_DTO_

#include "../../GlobalInclude.h"

/**
 * 传输对象 —— 单据编号（根据单据编号匹配对应的明细列表）
 */

//指定询价单的明细分录 
class EntryPurInquiryDTO
{
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // 对应mysql数据库中bill_no字段

public:
	// 绑定from_json
	friend void from_json(const json& j, EntryPurInquiryDTO& t);  // NOLINT
	BIND_TO_JSON(EntryPurInquiryDTO, purInquiryBillNo);
};

#endif // !_ENTRY_PUR_INQUIRY_DTO_