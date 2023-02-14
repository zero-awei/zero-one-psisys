#pragma once
#include "stdafx.h"
#include "DeleteSupplierDTO.h"


void from_json(const json& j, DeleteSupplierDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, rule);
	BIND_FROM_TO_NORMAL(j, t, name);
	BIND_FROM_TO_I(j, t, condition);
	BIND_FROM_TO_NORMAL(j, t, value);
}



