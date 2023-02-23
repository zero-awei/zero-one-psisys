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
#ifndef _STKIO_DO_
#define _STKIO_DO_
#include "../DoInclude.h"

/**
 * stk_io数据库实体类
 */
class StkIoDO
{
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
	//红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//出入库类型
	CC_SYNTHESIZE(string, stockIoType, StockIoType);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//出入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//有来往
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//是否有涨吨
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//客户
	CC_SYNTHESIZE(string, customerId, CustomerId);
	//发票类型
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//成本
	CC_SYNTHESIZE(double, cost, Cost);
	//结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
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
	//制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);	
	//制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//版本
	CC_SYNTHESIZE(string, version, Version);



public:
	StkIoDO() {
		id = "";
		billNo = "";
		billDate = "";
		srcBillType = "";
		srcBillId = "";
		srcNo = "";
		subject = "";
		isRubric = -1;
		stockIoType = "";
		opDept = "";
		operator1 = "";
		handler = "";
		hasRp = -1;
		hasSwell = -1;
		supplierId = "";
		customerId = "";
		invoiceType = "";
		cost = -1;
		settleAmt = -1;
		settledAmt = -1;
		invoicedAmt = -1;
		attachment = "";
		remark = "";
		isAuto = -1;
		billStage = "";
		approver = "";
		bpmiInstanceId = "";
		approvalResultType = "";
		approvalRemark = "";
		isEffective = -1;
		effectiveTime = "";
		isClosed = -1;
		isVoided = -1;
		sysOrgCode = "";
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
		version = "";




	}
};

#endif // !_STKIO_DO_
