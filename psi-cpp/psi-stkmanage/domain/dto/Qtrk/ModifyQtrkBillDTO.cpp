
#include "stdafx.h"
#include "ModifyQtrkBillDTO.h"
void from_json(const json& j, ModifyQtrkBillDTO& t) { // NOLINT
	//BIND_FROM_TO_ULL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, supplierId);
	BIND_FROM_TO_I(j, t, handler);
	BIND_FROM_TO_I(j, t, remark);
	BIND_FROM_TO_I(j, t, appFile);
}