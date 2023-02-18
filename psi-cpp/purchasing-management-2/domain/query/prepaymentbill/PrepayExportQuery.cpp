

#include "stdafx.h"
#include "PrePayExportQuery.h"

void from_json(const json& j, PrePayExportQuery& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, prepayId);
}