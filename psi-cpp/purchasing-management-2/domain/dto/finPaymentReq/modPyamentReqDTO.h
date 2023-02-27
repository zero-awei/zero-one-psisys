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
#ifndef _MOD_PAY_APPLY_DTO_
#define _MOD_PAY_APPLY_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

class ModPyamentReqDTO :public FileDTO
{
	//单据编号
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
	//付款类型
	CC_SYNTHESIZE(string, paymentType, PaymentType);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//核批结果类型
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//创建部门
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, updateTime);
	//版本
	CC_SYNTHESIZE(int, version, Version);
	//明细列表
	CC_SYNTHESIZE(list<FinPaymentReqEtryDTO>, detail, Detail);

public:
	//绑定JSON转换方法
	friend void from_json(const json& j, ModPyamentReqDTO& t) {
		BIND_FROM_TO_ULL(j, t, billNo);
		BIND_FROM_TO_ULL(j, t, billDate);
		BIND_FROM_TO_ULL(j, t, srcBillType);
		BIND_FROM_TO_ULL(j, t, srcBillId);
		BIND_FROM_TO_ULL(j, t, srcNo);
		BIND_FROM_TO_ULL(j, t, subject);
		BIND_FROM_TO_ULL(j, t, paymentType);
		BIND_FROM_TO_ULL(j, t, supplierId);
		BIND_FROM_TO_ULL(j, t, opDept);
		BIND_FROM_TO_ULL(j, t, operator1);
		BIND_FROM_TO_ULL(j, t, remark);
		BIND_FROM_TO_ULL(j, t, billStage);
		BIND_FROM_TO_ULL(j, t, approver);
		BIND_FROM_TO_ULL(j, t, bpmiInstanceId);
		BIND_FROM_TO_ULL(j, t, approvalRemark);
		BIND_FROM_TO_ULL(j, t, effectiveTime);
		BIND_FROM_TO_ULL(j, t, attachment);
		BIND_FROM_TO_ULL(j, t, sysOrdCode);
		BIND_FROM_TO_ULL(j, t, createBy);
		BIND_FROM_TO_ULL(j, t, createTime);
		BIND_FROM_TO_ULL(j, t, updateBy);
		BIND_FROM_TO_ULL(j, t, updateTime);
		BIND_FROM_TO_ULL(j, t, version);

		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, paidAmt);

		BIND_FROM_TO_I(j, t, isAuto);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);

		BIND_FROM_TO_OBJ(j, t, detail, list<FinPaymentReqEtryDTO>);
	}
};

#endif