
#include "stdafx.h"
#include "AddPurReqDTO.h"

void from_json(const json& j, AddPurReqDTO& t) {

	BIND_FROM_TO_I(j, t, isRubric);
	BIND_FROM_TO_I(j, t, isAuto);
	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);

	BIND_FROM_TO_D(j, t, qty);
	BIND_FROM_TO_D(j, t, amt);
	BIND_FROM_TO_D(j, t, orderedQty);

	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, srcNo);
	BIND_FROM_TO_NORMAL(j, t, srcBillType);
	BIND_FROM_TO_NORMAL(j, t, srcBillId);
	BIND_FROM_TO_NORMAL(j, t, purType);
	BIND_FROM_TO_NORMAL(j, t, requester);
	BIND_FROM_TO_NORMAL(j, t, requestTime);

	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_NORMAL(j, t, effectiveTime);
}


