#include "stdafx.h"
#include "DocListQuery.h"

void from_json(const json& j, DocListQuery& t)
{
	BIND_FROM_TO_ULL(j, t, pageIndex);
	BIND_FROM_TO_ULL(j, t, pageSize);
	BIND_FROM_TO_NORMAL(j, t, bill_no);
	BIND_FROM_TO_NORMAL(j, t, bill_date);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, supplier_id);
	BIND_FROM_TO_NORMAL(j, t, bill_stage);
	BIND_FROM_TO_I(j, t, is_eff);
	BIND_FROM_TO_I(j, t, is_closed);
	BIND_FROM_TO_I(j, t, is_voided);
}
