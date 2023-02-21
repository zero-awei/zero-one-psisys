#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _PURORDER_DO_
#define _PURORDER_DO_
#include "../DoInclude.h"

/**
 * pur_order数据库实体类
 */
class PurOrderDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//是否红字
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//采购类型
	CC_SYNTHESIZE(string, purType, PurType);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//联系人
	CC_SYNTHESIZE(string, contact, Contact);
	//联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	//传真
	CC_SYNTHESIZE(string, fax, Fax);
	//电子邮件
	CC_SYNTHESIZE(string, email, Email);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//交货方式
	CC_SYNTHESIZE(string, deliveryMethod, DeliveryMethod);
	//交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	//运输方式
	CC_SYNTHESIZE(string, transportMethod, TransportMethod);
	//付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	//结算方式
	CC_SYNTHESIZE(string, settleMethod, SettleMethod);
	//结算日期
	CC_SYNTHESIZE(string, settleTime, SettleTime);
	//开票方式
	CC_SYNTHESIZE(string, invoiceMethod, InvoiceMethod);
	//发票类型
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//外币币种
	CC_SYNTHESIZE(string, currency, Currency);
	//汇率
	CC_SYNTHESIZE(double, exchangeRate, ExchangeRate);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//金额
	CC_SYNTHESIZE(double, amt, Amt);
	//预付款余额
	CC_SYNTHESIZE(double, prepaymentBal, PrepaymentBal);
	//结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//已入库数量
	CC_SYNTHESIZE(double, inQty, InQty);
	//已入库成本
	CC_SYNTHESIZE(double, inCost, InCost);
	//已结算金额
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//创建部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//版本
	CC_SYNTHESIZE(string, version, Version);



public:
	StkIoDO() {


	}
};

#endif // !_STKIO_DO_
