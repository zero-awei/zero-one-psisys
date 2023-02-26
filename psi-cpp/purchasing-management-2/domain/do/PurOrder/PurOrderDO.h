#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/15 12:02:32

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
#ifndef _PUR_ORDER_DO_
#define _PUR_ORDER_DO_
#include "../DoInclude.h"

/**
 * 采购订单数据库实体类
 */
class PurOrderDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// 源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	// 源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// 采购类型
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// 联系人
	CC_SYNTHESIZE(string, contact, Contact);
	// 联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	// 传真
	CC_SYNTHESIZE(string, fax, Fax);
	// 电子邮件
	CC_SYNTHESIZE(string, email, Email);
	// 业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	// 业务员
	CC_SYNTHESIZE(string, op_er, Op_er);
	// 交货方式
	CC_SYNTHESIZE(string, delivery_method, Delivery_method);
	// 交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
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
	// 开票方式
	CC_SYNTHESIZE(string, invoice_method, Invoice_method);
	// 发票类型	
	CC_SYNTHESIZE(string, invoice_type, Invoice_type);
	// 外币币种
	CC_SYNTHESIZE(string, currency, Currency);
	// 汇率
	CC_SYNTHESIZE(double, exchange_rate, Exchange_rate);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 金额
	CC_SYNTHESIZE(float, amt, Amt);
	// 预付余款	
	CC_SYNTHESIZE(float, prepayment_bal, Prepayment_bal);
	// 结算数量
	CC_SYNTHESIZE(double, settle_qty, Settle_qty);
	// 结算金额
	CC_SYNTHESIZE(float, settle_amt, Settle_amt);
	// 已入库数量		
	CC_SYNTHESIZE(double, in_qty, In_qty);
	// 已入库成本
	CC_SYNTHESIZE(float, in_cost, In_cost);
	// 已结算金额
	CC_SYNTHESIZE(float, settled_amt, Settled_amt);
	// 已开票金额
	CC_SYNTHESIZE(float, invoiced_amt, Invoiced_amt);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否自动生成:自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 单据阶段		
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 审核人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	// 核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	// 核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 创建部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 版本
	CC_SYNTHESIZE(int, version, Version);
public:
	PurOrderDO() {
		exchange_rate = 0.0;
		qty = 0.0;
		amt = 0.0;
		prepayment_bal = 0.0;
		settle_amt = 0.0;
		settle_qty = 0.0;
		in_qty = 0.0;
		in_cost = 0.0;
		settled_amt = 0.0;
		invoiced_amt = 0.0;
		is_rubric = -1;
		is_auto = -1;
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
		version = -1;
	}
};

#endif // !_PUR_ORDER_DO_
