#include "stdafx.h"
#include "PurReqExportDTO.h"

void from_json(const json& j, PurReqExportDTO& t) { // NOLINT
	BIND_FROM_TO_OBJ(j, t, purReqId, std::list<string>);
}