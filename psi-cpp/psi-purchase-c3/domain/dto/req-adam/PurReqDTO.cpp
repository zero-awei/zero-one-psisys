#include "stdafx.h"
#include "PurReqDTO.h"
void from_json(const json& j, PurReqDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, name);
	BIND_FROM_TO_I(j, t, age);
	BIND_FROM_TO_NORMAL(j, t, sex);
}