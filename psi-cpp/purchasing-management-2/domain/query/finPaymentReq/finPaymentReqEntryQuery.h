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
#ifndef _FIN_PAYMENT_REQ_ENTRY_QUERY_
#define _FIN_PAYMENT_REQ_ENTRY_QUERY_


#include "../PageQuery.h"
/*
查询单据列表
*/
class FinPaymentReqEntryQuery {
	//单据号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//分录号
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
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
	friend void from_json(const json& j, FinPaymentReqEntryQuery& t) {
		BIND_FROM_TO_ULL(j, t, billNo);
		BIND_FROM_TO_ULL(j, t, srcBillType);
		BIND_FROM_TO_ULL(j, t, srcEntryId);
		BIND_FROM_TO_ULL(j, t, srcBillId);
		BIND_FROM_TO_I(j, t, entryNo);
		BIND_FROM_TO_ULL(j, t, srcNo);
		BIND_FROM_TO_ULL(j, t, remark);
		BIND_FROM_TO_ULL(j, t, custom1);
		BIND_FROM_TO_ULL(j, t, custom2);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, paidAmt);
	}
};

#endif //_FIN_PAYMENT_REQ_ENTRY_QUERY_