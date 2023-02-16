#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Papillon
 @Date: 2023/02/16 22:00:00
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
#ifndef _PAYMENT_BILL_DETAIL_QUERY_
#define _PAYMENT_BILL_DETAIL_QUERY_

#include "../PageQuery.h"

/*
查询单据列表
*/
class PaymentBillDetailQuery {
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentBillDetailQuery, srcNo, amt, paidAmt, remark, custom1, custom2);
};

#endif