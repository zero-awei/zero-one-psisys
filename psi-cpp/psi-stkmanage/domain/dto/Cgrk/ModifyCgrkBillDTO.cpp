#include "stdafx.h"
#include "ModifyCgrkBillDTO.h"


void from_json(const json& j, ModifyCgrkBillDTO& t)
{
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, opDept);
	BIND_FROM_TO_NORMAL(j, t, operator1);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, attachment);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, bpmiInstanceId);
	BIND_FROM_TO_NORMAL(j, t, createBy);
	BIND_FROM_TO_NORMAL(j, t, createTime);
	BIND_FROM_TO_NORMAL(j, t, sysOrgCode);
	BIND_FROM_TO_NORMAL(j, t, updateTime);
	BIND_FROM_TO_NORMAL(j, t, updateBy);
	BIND_FROM_TO_I(j, t, isAuto);
	BIND_FROM_TO_I(j, t, isRubric);
	BIND_FROM_TO_I(j, t, hasRp);
}