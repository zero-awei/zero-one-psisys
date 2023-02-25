#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2022/2/21 8:50:55

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
#ifndef _PUR_REQ_ADAM_DO_H_
#define _PUR_REQ_ADAM_DO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PurReqAdamDO
{
	//单据id
	CC_SYNTHESIZE(string, id, Id);
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
	//是否红字
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//采购类型
	CC_SYNTHESIZE(string, purType, PurType);

	//需求部门
	CC_SYNTHESIZE(string, requestDept, RequestDept);
	//需求人
	CC_SYNTHESIZE(string, requester, Requester);
	//需求时间
	CC_SYNTHESIZE(string, requestTime, RequestTime);

	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已订数量
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);

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
	//审批id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);

	//核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
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
	CC_SYNTHESIZE(int, version, Version);

public:
	PurReqAdamDO() {
		//源单类型
		srcBillType = "";
		//源单id
		srcBillId = "";
		//源单号
		srcNo = "";
		//单据主题
		subject = "";
		//是否红字
		isRubric = 0;
		//采购类型
		purType = "";
		//数量
		qty = 0.000000;
		//参考金额
		amt = 0.00;
		//已订数量
		orderedQty = 0.000000;
		//附件
		attachment = "";
		//备注
		remark = "";
		//是否自动生成
		isAuto = 0;
		//审核人
		approver = "";
		//审批id
		bpmiInstanceId = "";
		//核批结果类型
		approvalResultType = "";
		//核批意见
		approvalRemark = "";
		//是否生效
		isEffective = 0;
		//生效时间
		effectiveTime = "";
		//是否已关闭
		isClosed = 0;
		//是否作废
		isVoided = 0;
		//修改人
		updateBy = "";
		//修改时间
		updateTime = "";
		//版本
		version = -1;
	}
};

#endif // !_PUR_REQ_ADAM_DO_H_
