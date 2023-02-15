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
#ifndef _PUR_INQUIRY_FIND_BILL_DTO_
#define _PUR_INQUIRY_FIND_BILL_DTO_

#include "../../GlobalInclude.h"

/**
 * 传输对象 —— 采购询价单查询信息列表
 */

//采购询价单列表
class PurInquiryFindBillDTO: public PayloadDTO
{
//传输对象参数 - 基本信息string
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, PurInquiryBillDate);
	//单据主题
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
//单据状态
	//是否生效int
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurInquiryFindBillDTO& t); // NOLINT
	BIND_TO_JSON(PurInquiryFindBillDTO, purInquiryBillNo, purInquiryBillDate, purInquirySubject,
		purInquiryIsEffective, purInquiryIsClosed, purInquiryIsVoided);

};

#endif // !_PUR_INQUIRY_FIND_BILL_DTO_