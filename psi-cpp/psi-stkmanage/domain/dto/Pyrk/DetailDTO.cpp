#include "stdafx.h"
#include "DetailDTO.h"

void from_json(const json& j, DetailDTO& t) { // NOLINT
	BIND_FROM_TO_I(j, t, entryNo);
	BIND_FROM_TO_NORMAL(j, t, material);
	BIND_FROM_TO_NORMAL(j, t, warehouse);
	BIND_FROM_TO_NORMAL(j, t, unit);
	BIND_FROM_TO_D(j, t, qty);
	BIND_FROM_TO_D(j, t, cost);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
}
