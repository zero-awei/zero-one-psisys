#pragma once
#ifndef _PUR_QUOT_MOD_BILL_STATUS_DTO_H_
#define _PUR_QUOT_MOD_BILL_STATUS_DTO_H_
#include "../../GlobalInclude.h"


class PurQuotModBillStatusDTO
{
	//以下有一些字段，我不确定是否真的会用到，如果之后写代码，发现还需要其他字段，就添加上去；不需要再删除；
	// 单据id
	CC_SYNTHESIZE(long, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据阶段
	CC_SYNTHESIZE(int, billStage, BillStage);
	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
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

public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PurQuotModBillStatusDTO& t) {
		BIND_FROM_TO_L(j, t, id);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_I(j, t, approvalResultType);
		BIND_FROM_TO_I(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
	}
};

#endif // !_PUR_QUOT_MOD_BILL_STATUS_DTO_