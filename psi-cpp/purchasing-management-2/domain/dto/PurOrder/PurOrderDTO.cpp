/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/15 11:59:38

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
#include "stdafx.h"
#include "PurOrderDTO.h"
void from_json(const json& j, PurOrderDTO& t) { // NOLINT
	// 单据编号
	BIND_FROM_TO_NORMAL(j, t, bill_no);
	// 单据日期
	BIND_FROM_TO_NORMAL(j, t, bill_date);
	// 源单类型
	BIND_FROM_TO_NORMAL(j, t, src_bill_type);
	// 源单id
	BIND_FROM_TO_NORMAL(j, t, src_bill_id);
	// 源单号
	BIND_FROM_TO_NORMAL(j, t, src_no);
	// 单据主题
	BIND_FROM_TO_NORMAL(j, t, subject);
	// 红字单据
	BIND_FROM_TO_I(j, t, is_rubric);
	// 采购类型
	BIND_FROM_TO_NORMAL(j, t, pur_type);
	// 供应商
	BIND_FROM_TO_NORMAL(j, t, supplier_id);
	// 联系人
	BIND_FROM_TO_NORMAL(j, t, contact);
	// 联系电话
	BIND_FROM_TO_NORMAL(j, t, phone);
	// 传真
	BIND_FROM_TO_NORMAL(j, t, fax);
	// 电子邮件
	BIND_FROM_TO_NORMAL(j, t, email);
	// 业务部门
	BIND_FROM_TO_NORMAL(j, t, op_dept);
	// 业务员
	BIND_FROM_TO_NORMAL(j, t, op_er);
	// 交货方式
	BIND_FROM_TO_NORMAL(j, t, delivery_method);
	// 交货地点
	BIND_FROM_TO_NORMAL(j, t, delivery_place);
	// 交货日期	
	BIND_FROM_TO_NORMAL(j, t, delivery_time);
	// 运输方式
	BIND_FROM_TO_NORMAL(j, t, transport_method);
	// 付款方式	
	BIND_FROM_TO_NORMAL(j, t, payment_method);
	// 结算方式	
	BIND_FROM_TO_NORMAL(j, t, settle_method);
	// 结算日期	
	BIND_FROM_TO_NORMAL(j, t, settle_time);
	// 开票方式
	BIND_FROM_TO_NORMAL(j, t, invoice_method);
	// 发票类型	
	BIND_FROM_TO_NORMAL(j, t, invoice_type);
	// 外币币种
	BIND_FROM_TO_NORMAL(j, t, currency);
	// 汇率
	BIND_FROM_TO_D(j, t, exchange_rate);
	// 数量
	BIND_FROM_TO_D(j, t, qty);
	// 金额
	BIND_FROM_TO_F(j, t, amt);
	// 预付余款	
	BIND_FROM_TO_F(j, t, prepayment_bal);
	// 结算数量
	BIND_FROM_TO_D(j, t, settle_qty);
	// 结算金额
	BIND_FROM_TO_F(j, t, settle_amt);
	// 已入库数量		
	BIND_FROM_TO_D(j, t, in_qty);
	// 已入库成本
	BIND_FROM_TO_F(j, t, in_cost);
	// 已结算金额
	BIND_FROM_TO_F(j, t, settled_amt);
	// 已开票金额
	BIND_FROM_TO_F(j, t, invoiced_amt);
	// 附件
	BIND_FROM_TO_NORMAL(j, t, attachment);
	//备注
	BIND_FROM_TO_NORMAL(j, t, remark);
	// 是否自动生成:自动单据
	BIND_FROM_TO_I(j, t, is_auto);
	// 单据阶段		
	BIND_FROM_TO_NORMAL(j, t, bill_stage);
	// 审核人
	BIND_FROM_TO_NORMAL(j, t, approver);
	// 审批实例id
	BIND_FROM_TO_NORMAL(j, t, bpmi_instance_id);
	// 核批结果类型
	BIND_FROM_TO_NORMAL(j, t, approve_result_type);
	// 核批意见
	BIND_FROM_TO_NORMAL(j, t, approve_remark);
	// 是否生效
	BIND_FROM_TO_I(j, t, is_effective);
	// 生效时间
	BIND_FROM_TO_NORMAL(j, t, effective_time);
	// 是否关闭
	BIND_FROM_TO_I(j, t, is_closed);
	// 是否作废
	BIND_FROM_TO_I(j, t, is_voided);
	// 创建部门
	BIND_FROM_TO_NORMAL(j, t, sys_org_code);
	// 创建人
	BIND_FROM_TO_NORMAL(j, t, create_by);
	// 创建时间
	BIND_FROM_TO_NORMAL(j, t, create_time);
	// 修改人
	BIND_FROM_TO_NORMAL(j, t, update_by);
	// 修改时间
	BIND_FROM_TO_NORMAL(j, t, update_time);
	// 版本
	BIND_FROM_TO_I(j, t, version);
}