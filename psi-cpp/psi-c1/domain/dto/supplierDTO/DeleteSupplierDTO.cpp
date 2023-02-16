#pragma once
#include "stdafx.h"
#include "DeleteSupplierDTO.h"


void from_json(const json& j, DeleteSupplierDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, code);
}



