#include "stdafx.h"
#include "AddPayDTO.h"
#include "PrepaymentDTO.h"

void from_json(const json& j, AddPayDTO & t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, bill_no);
	BIND_FROM_TO_NORMAL(j, t, bill_date);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, op);
	BIND_FROM_TO_NORMAL(j, t, op_dept);
	BIND_FROM_TO_NORMAL(j, t, supplier_id);

	BIND_FROM_TO_I(j, t, amt);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
	BIND_FROM_TO_NORMAL(j, t, attachment);

	BIND_FROM_TO_NORMAL(j, t, bill_stage);
	BIND_FROM_TO_B(j, t, is_effective);
	BIND_FROM_TO_B(j, t, is_closed);
	BIND_FROM_TO_B(j, t, is_voided);

}