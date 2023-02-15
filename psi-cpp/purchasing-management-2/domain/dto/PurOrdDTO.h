#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _PUR_ORDER_DTO_
#define _PUR_ORDER_DTO_

#include "../../GlobalInclude.h"

/**
 * 
 */
namespace PUR_ORDER_DTO {
	class PurOrderDTO
	{
		// 单据编号
		CC_SYNTHESIZE(string, bill_no, Bill_no);
		// 单据日期
		CC_SYNTHESIZE(string, bill_date, Bill_date);
		// 单据主题
		CC_SYNTHESIZE(string, subject, Subject);
		// 红字单据
		CC_SYNTHESIZE(int, is_rubric, Is_rubric);
		// 采购类型
		CC_SYNTHESIZE(int, pur_type, Pur_type);
		// 供应商
		CC_SYNTHESIZE(string, supplier_id, Supplier_id);
		// 业务部门
		CC_SYNTHESIZE(string, op_dept, Op_dept);
		// 业务员
		CC_SYNTHESIZE(string, operator, Operator);
		// 交货方式
		CC_SYNTHESIZE(string, delivery_method, Delivery_method);
		// 交货日期	
		CC_SYNTHESIZE(string, delivery_time, Delivery_time);
		// 运输方式
		CC_SYNTHESIZE(string, transport_method, Transport_method);
		// 付款方式	
		CC_SYNTHESIZE(string, payment_method, Payment_method);
		// 结算方式	
		CC_SYNTHESIZE(string, settle_method, Settle_method);
		// 结算日期	
		CC_SYNTHESIZE(string, settle_time, Settle_time);
		//发票类型	
		CC_SYNTHESIZE(string, invoice_type, Invoice_type);
		//数量
		CC_SYNTHESIZE(uint64_t, qty, Qty);
		//金额		
		CC_SYNTHESIZE(float, amt, Amt);
		//预付余款	
		CC_SYNTHESIZE(float, prepayment_bal, Prepayment_bal);
		//结算数量
		CC_SYNTHESIZE(uint64_t, settle_qty, Settle_qty);
		//结算金额
		CC_SYNTHESIZE(float, settle_amt, Settle_amt);
		//已入库数量		
		CC_SYNTHESIZE(uint64_t, in_qty, In_qty);
		//已入库金额
		CC_SYNTHESIZE(float, in_cost, In_cost);
		//已结算金额
		CC_SYNTHESIZE(float, settle_amt, settle_amt);
		//自动单据
		CC_SYNTHESIZE(int, is_auto, Is_auto);
		//单据阶段		
		CC_SYNTHESIZE(int, bill_stage, Bill_stage);
		//备注
		CC_SYNTHESIZE(string, remark, Remark);
		//核批人
		CC_SYNTHESIZE(string, approver, Approver);
		//已生效
		CC_SYNTHESIZE(int, is_effective, Is_effective);
		//生效时间
		CC_SYNTHESIZE(string, effective_time, Effective_time);
		//已关闭
		CC_SYNTHESIZE(int, is_closed, Is_closed);
		//已作废
		CC_SYNTHESIZE(int, is_voided, Is_voided);	
		//制单部门
		CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
		//制单人
		CC_SYNTHESIZE(string, create_by, Create_by);
		//制单时间
		CC_SYNTHESIZE(string, create_time, Create_time);
		//修改人
		CC_SYNTHESIZE(string, updateBy, UpdateBy);	
		//修改时间
		CC_SYNTHESIZE(string, updateTime, UpdateTime);
		
	public:
		// 绑定JSON转换方法
		friend void from_json(const json& j, PurOrderDTO& t); // NOLINT
		BIND_TO_JSON(PurOrderDTO, bill_no, bill_date, subject, \
			is_rubric, pur_type, supplier_id, op_dept, operator, \
			delivery_method, delivery_time, transport_method, \
			payment_method, settle_method, settle_time, \
			invoice_type, qty, amt, prepayment_bal, settle_qty, \
			settle_amt, in_qty, in_cost, settle_amt, is_auto, \
			bill_stage, remark, approver, is_effective, \
			effective_time, is_closed, is_voided, sys_org_code, \
			create_time, updateBy, updateTime);
	};
}


#endif // !_PUR_ORDER_DTO_