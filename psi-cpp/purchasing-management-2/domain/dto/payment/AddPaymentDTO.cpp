
#include "stdafx.h"
#include "AddPaymentDTO.h"

void from_json(const json& j, AddPaymentDTO& apt) {
	BIND_FROM_TO_NORMAL(j, apt, bill_no);
	BIND_FROM_TO_NORMAL(j, apt, bill_date);
	BIND_FROM_TO_NORMAL(j, apt, src_bill_type);
	BIND_FROM_TO_NORMAL(j, apt, src_bill_id);
	BIND_FROM_TO_NORMAL(j, apt, src_no);
	BIND_FROM_TO_NORMAL(j, apt, subject);
	BIND_FROM_TO_NORMAL(j, apt, supplier_id);
	BIND_FROM_TO_NORMAL(j, apt, op_dept);
	BIND_FROM_TO_NORMAL(j, apt, operator1);
	BIND_FROM_TO_NORMAL(j, apt, payment_type);
	BIND_FROM_TO_NORMAL(j, apt, remark);
	BIND_FROM_TO_NORMAL(j, apt, bill_stage);
	BIND_FROM_TO_NORMAL(j, apt, effective_time);

	BIND_FROM_TO_I(j, apt, amt);
	BIND_FROM_TO_I(j, apt, is_auto);
	BIND_FROM_TO_I(j, apt, is_effective);
	BIND_FROM_TO_I(j, apt, is_closed);
	BIND_FROM_TO_I(j, apt, is_voided);
}