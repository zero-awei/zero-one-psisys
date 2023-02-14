#include "stdafx.h"
#include "PurReqAdamDTO.h"

void from_json(const json& j, AddAndModifyPurReqDTO& t) {

	BIND_FROM_TO_I(j, t, isAuto);
	BIND_FROM_TO_I(j, t, approvalResultType);
	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);
	BIND_FROM_TO_I(j, t, version);

	BIND_FROM_TO_D(j, t, qty);
	BIND_FROM_TO_D(j, t, amt);
	BIND_FROM_TO_D(j, t, orderedQty);

	BIND_FROM_TO_NORMAL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, srcNo);
	BIND_FROM_TO_NORMAL(j, t, srcBillType);
	BIND_FROM_TO_NORMAL(j, t, srcBillId);
	BIND_FROM_TO_NORMAL(j, t, purType);
	BIND_FROM_TO_NORMAL(j, t, requester);
	BIND_FROM_TO_NORMAL(j, t, requestTime);
	BIND_FROM_TO_NORMAL(j, t, attachment);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, bpmiInstanceId);
	BIND_FROM_TO_NORMAL(j, t, approvalRemark);
	BIND_FROM_TO_NORMAL(j, t, effectiveTime);
	BIND_FROM_TO_NORMAL(j, t, sysOrdCode);
	BIND_FROM_TO_NORMAL(j, t, createBy);
	BIND_FROM_TO_NORMAL(j, t, createTime);
	BIND_FROM_TO_NORMAL(j, t, updateBy);
	BIND_FROM_TO_NORMAL(j, t, updateTime);
}
void from_json(const json& j, DeletePurDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billNo);
}

void from_json(const json& j, PurReqModBillStatusDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, effectiveTime);

	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);
}
