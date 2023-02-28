#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:15:16

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
#ifndef _PUR_COMPARE_DO_
#define _PUR_COMPARE_DO_
#include "../DoInclude.h"

/**
 * pur_compare数据库实体类
 */
class PurCompareDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	// 源单号(采购询价单)
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 红字单据
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// 候选报价单ids
	CC_SYNTHESIZE(string, candidateQuotIds, CandidateQuotIds);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自动单据
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 核批实例
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// 核批结果
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	// 核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	// 已生效
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// 已关闭
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// 制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// 制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 版本
	CC_SYNTHESIZE(string, version, Version);
	// 单据日期_开始
	CC_SYNTHESIZE(string, billDateBegin, BillDateBegin);
	// 单据日期_结束
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
public:
	PurCompareDO() {
		billNo = "";
	}
	PurCompareDO(vector<string> vecStr) {
		int i = 0;
		setBillNo(vecStr[i++]);
		setBillDate(vecStr[i++]);
		setSrcBillType(vecStr[i++]);
		setSrcBillId(vecStr[i++]);
		setSrcNo(vecStr[i++]);
		setSubject(vecStr[i++]);
		setIsRubric(vecStr[i++]);
		setCandidateQuotIds(vecStr[i++]);
		setPaymentMethod(vecStr[i++]);
		setDeliveryPlace(vecStr[i++]);
		setDeliveryTime(vecStr[i++]);
		setAttachment(vecStr[i++]);
		setRemark(vecStr[i++]);
		setIsAuto(vecStr[i++]);
		setBillStage(vecStr[i++]);
		setApprover(vecStr[i++]);
		setBpmiInstanceId(vecStr[i++]);
		setApprovalResultType(vecStr[i++]);
		setApprovalRemark(vecStr[i++]);
		setIsEffective(vecStr[i++]);
		setEffectiveTime(vecStr[i++]);
		setIsClosed(vecStr[i++]);
		setIsVoided(vecStr[i++]);
		setSysOrgCode(vecStr[i++]);
		setCreateBy(vecStr[i++]);
		setCreateTime(vecStr[i++]);
		setUpdateBy(vecStr[i++]);
		/*setUpdateTime(vecStr[i++]);*/
	}
	vector<string> purCompareDOToVecStr() {
		vector<string> vecStr{getBillNo(),getBillDate(),getSrcBillType(),getSrcBillId(),getSrcNo(),
			getSubject(),getIsRubric(),getCandidateQuotIds(),getPaymentMethod(),getDeliveryPlace(),
			getDeliveryTime(),getAttachment(),getRemark(),getIsAuto(),getBillStage(),getApprover(),
			getBpmiInstanceId(),getApprovalResultType(),getApprovalRemark(),getIsEffective(),
			getEffectiveTime(),getIsClosed(),getIsVoided(),getSysOrgCode(),getCreateBy(),getCreateTime(),
			getUpdateBy()/*,getUpdateTime()*/};
		return vecStr;
	}
};

#endif 

