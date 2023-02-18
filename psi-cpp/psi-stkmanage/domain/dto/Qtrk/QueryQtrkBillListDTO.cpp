
#include "stdafx.h"
#include "QueryQtrkBillListDTO.h"
void from_json(const json& j, QueryQtrkBillListDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, billDateStart);
	BIND_FROM_TO_NORMAL(j, t, billDateEnd);
	BIND_FROM_TO_NORMAL(j, t, supplierId);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);
}