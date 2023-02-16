#include "stdafx.h"
#include "AddCgrkBillDTO.h"



void from_json(const json& j, AddCgrkBillDTO& t)
{
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, opDept);
	BIND_FROM_TO_NORMAL(j, t, operatoR);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_I(j, t, entryNo);
	BIND_FROM_TO_NORMAL(j, t, materialId);
	BIND_FROM_TO_NORMAL(j, t, model);
	BIND_FROM_TO_NORMAL(j, t, warehouseId);
	BIND_FROM_TO_NORMAL(j, t, unitId);
	BIND_FROM_TO_D(j, t, swellQty);
	BIND_FROM_TO_D(j, t, inCost);
	BIND_FROM_TO_NORMAL(j, t, remark1);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
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