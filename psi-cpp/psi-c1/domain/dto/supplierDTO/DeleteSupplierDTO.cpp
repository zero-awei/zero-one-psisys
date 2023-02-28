#include "stdafx.h"
#include "DeleteSupplierDTO.h"


void from_json(const json& j, DeleteSupplierDTO& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, id);
}



