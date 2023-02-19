#include "stdafx.h"
#include"PyrkBillDetailDTO.h"
void from_json(const json& j, PyrkBillDetailDTO& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_I(j, t, save);
	BIND_FROM_TO_OBJ(j, t, detail, list<DetailDTO>);
}