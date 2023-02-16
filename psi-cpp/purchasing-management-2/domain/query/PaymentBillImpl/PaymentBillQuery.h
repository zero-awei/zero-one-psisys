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
#ifndef _PAYMENT_BILL_Query_
#define _PAYMENT_BILL_Query_

#include "../PageQuery.h"


//查询单据列表
class PaymentBillQuery : public PageQuery {
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId)
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭			
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PaymentBillQuery& pbq) {
		BIND_FROM_TO_ULL(j, pbq, billNo);
		BIND_FROM_TO_ULL(j, pbq, billDate);
		BIND_FROM_TO_ULL(j, pbq, subject);
		BIND_FROM_TO_ULL(j, pbq, supplierId);
		BIND_FROM_TO_ULL(j, pbq, billStage);
		BIND_FROM_TO_I(j, pbq, isEffective);
		BIND_FROM_TO_I(j, pbq, isClosed);
		BIND_FROM_TO_I(j, pbq, isVoided);
	}
};


/*
查询指定单据详细信息
*/
class PaymentBillDetailQuery {
	//指定的单据号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PaymentBillDetailQuery& pbdq) {
		BIND_FROM_TO_ULL(j, pbdq, billNo);
	}
};


#endif
