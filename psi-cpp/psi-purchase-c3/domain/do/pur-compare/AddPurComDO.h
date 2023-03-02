#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\18 13:27:49

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
#ifndef _ADD_PUR_COM_DO_H_
#define _ADD_PUR_COM_DO_H_
#include "../DoInclude.h"
#include "../../dto/pur-compare/PurComDetailDTO.h"

/**
 * 示例数据库实体类
 */
class AddPurComDO
{
	// 数据id
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 源单ID
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);

	// 源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// subject
	CC_SYNTHESIZE(string, subject, Subject);
	// 是否红字
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// 候选报价单ids
	CC_SYNTHESIZE(string, candidateQuotIds, CandidateQuotIds);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);

	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 交货时间
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);

	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 审核人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// 核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	// 核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);

	// 是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// 已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// 创建部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);

	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 版本
	CC_SYNTHESIZE(int, version, Version);

	//明细
	CC_SYNTHESIZE(list<PurComDetailDTO>, detail, Detail);
public:
	AddPurComDO() {
		
	}
};

#endif // !_ADD_PUR_COM_DO_H_
