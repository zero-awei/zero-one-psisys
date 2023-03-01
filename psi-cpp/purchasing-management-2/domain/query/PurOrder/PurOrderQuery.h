#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/15 10:55:01

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
#ifndef _PUR_ORDER_QUERY_
#define _PUR_ORDER_QUERY_

#include "../PageQuery.h"

/**
 * 采购订单分页查询对象
 */
class PurOrderQuery : public PageQuery {
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 采购类型
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// 付款方式	
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	// 结算方式	
	CC_SYNTHESIZE(string, settle_method, Settle_method);
	// 结算日期	
	CC_SYNTHESIZE(string, settle_time, Settle_time);
	// 交货方式
	CC_SYNTHESIZE(string, delivery_method, Delivery_method);
	// 发票类型	
	CC_SYNTHESIZE(string, invoice_type, Invoice_type);



	// 业务员
	CC_SYNTHESIZE(string, op_er, Op_er);
	// 业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);

	
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurOrderQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);

		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, pur_type);
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		BIND_FROM_TO_NORMAL(j, t, settle_method);
		BIND_FROM_TO_NORMAL(j, t, settle_time);
		BIND_FROM_TO_NORMAL(j, t, delivery_method);
		BIND_FROM_TO_NORMAL(j, t, invoice_type);
		
		BIND_FROM_TO_NORMAL(j, t, op_er);
		BIND_FROM_TO_NORMAL(j, t, op_dept);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		
	}
};
#endif // !_PUR_ORDER_QUERY_




