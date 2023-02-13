#include "stdafx.h"
#include "AddDocListDTO.h"

void from_json(const json& j, AddDocListDTO& t) // NOLINT
{
	BIND_FROM_TO_NORMAL(j, t, bill_date);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, src_operator);
	BIND_FROM_TO_NORMAL(j, t, op_dept);
	BIND_FROM_TO_NORMAL(j, t, supplier_id);
	BIND_FROM_TO_NORMAL(j, t, src_no);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_D(j, t, settle_qty);
	BIND_FROM_TO_D(j, t, tax);
	BIND_FROM_TO_D(j, t, settle_amt);
	BIND_FROM_TO_D(j, t, cost);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
}
