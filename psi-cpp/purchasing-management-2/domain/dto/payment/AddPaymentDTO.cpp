
#include "stdafx.h"
#include "AddPaymentDTO.h"

void from_json(const json& j, AddPaymentDTO& apt) {
	BIND_FROM_TO_NORMAL(j, apt, bill_no);
	BIND_FROM_TO_NORMAL(j, apt, billDate);
	BIND_FROM_TO_NORMAL(j, apt, srcBillType);
	BIND_FROM_TO_NORMAL(j, apt, srcBillId);
	BIND_FROM_TO_NORMAL(j, apt, srcNo);
	BIND_FROM_TO_NORMAL(j, apt, subject);
	BIND_FROM_TO_NORMAL(j, apt, supplierId);
	BIND_FROM_TO_NORMAL(j, apt, opDept);
	BIND_FROM_TO_NORMAL(j, apt, operator1);
	BIND_FROM_TO_NORMAL(j, apt, paymentType);
	BIND_FROM_TO_NORMAL(j, apt, remark);
	BIND_FROM_TO_NORMAL(j, apt, billStage);
	BIND_FROM_TO_NORMAL(j, apt, effectiveTime);

	BIND_FROM_TO_I(j, apt, amt);
	BIND_FROM_TO_I(j, apt, isAuto);
	BIND_FROM_TO_I(j, apt, isEffective);
	BIND_FROM_TO_I(j, apt, isClosed);
	BIND_FROM_TO_I(j, apt, isVoided);
}