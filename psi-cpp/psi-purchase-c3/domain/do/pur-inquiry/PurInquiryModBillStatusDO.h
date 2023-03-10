#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/02/22 23:27:20

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
#ifndef _PUR_INQUIRY_MOD_BILL_STATUS_DO_H_
#define _PUR_INQUIRY_MOD_BILL_STATUS_DO_H_
#include "../../GlobalInclude.h"


class PurInquiryModBillStatusDO
{
	//已关闭			;
	CC_SYNTHESIZE(int, is_close, Is_close);
	//是否作废			;
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//订单编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	PurInquiryModBillStatusDO()
	{

	}

};

#endif // !_PUR_INQUIRY_MOD_BILL_STATUS_DO_H_