
#include "stdafx.h"
#include "AddQtrkBillDTO.h"
void from_json(const json& j, AddQtrkBillDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, bill);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, supplier);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, materialId);
	BIND_FROM_TO_NORMAL(j, t, model);//πÊ∏Ò–Õ∫≈
	BIND_FROM_TO_NORMAL(j, t, warehouseId);
	BIND_FROM_TO_NORMAL(j, t, depart);
	BIND_FROM_TO_I(j, t, inhouse);
	BIND_FROM_TO_D(j, t, permoney);
	BIND_FROM_TO_D(j, t, inCost);
	BIND_FROM_TO_NORMAL(j, t, remarK);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
	BIND_FROM_TO_NORMAL(j, t, attachment);
}