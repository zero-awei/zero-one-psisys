
#include "stdafx.h"
#include "DePayDTO.h"

void from_json(const json& j, DePayDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billNo);
}