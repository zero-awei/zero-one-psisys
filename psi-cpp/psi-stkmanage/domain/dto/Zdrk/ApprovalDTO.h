#pragma once
#ifndef _APPROVAL_DTO_
#define _APPROVAL_DTO_

#include "../../GlobalInclude.h"

/*
* 审核DTO
*/
class ApprovalDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 核批结果类型
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
	// 核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
public:
	friend void from_json(const json& j, ApprovalDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_I(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
	}
};

#endif // !_APPROVAL_DTO_