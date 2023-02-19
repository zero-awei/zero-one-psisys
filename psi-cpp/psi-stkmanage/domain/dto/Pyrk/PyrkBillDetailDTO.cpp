#include "stdafx.h"
#include"PyrkBillDetailDTO.h"
void from_json(const json& j, PyrkBillDetailDTO& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, data);
	BIND_FROM_TO_NORMAL(j, t, theme);
	BIND_FROM_TO_NORMAL(j, t, resourceId);
	BIND_FROM_TO_NORMAL(j, t, handing);

	BIND_FROM_TO_I(j, t, stage);
	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);

	BIND_FROM_TO_NORMAL(j, t, remarks);

	BIND_FROM_TO_I(j, t, isAuto);

	BIND_FROM_TO_NORMAL(j, t, effectiveData);
	BIND_FROM_TO_NORMAL(j, t, checkPerson);
	BIND_FROM_TO_NORMAL(j, t, makePerson);
	BIND_FROM_TO_NORMAL(j, t, makeData);
	BIND_FROM_TO_NORMAL(j, t, department);
	BIND_FROM_TO_NORMAL(j, t, modifyData);
	BIND_FROM_TO_NORMAL(j, t, modifyPerson);
	BIND_FROM_TO_NORMAL(j, t, checkInstanceId);

	BIND_FROM_TO_I(j, t, hasYF);
	BIND_FROM_TO_I(j, t, redBill);

	BIND_FROM_TO_NORMAL(j, t, sourceBillType);
	BIND_FROM_TO_NORMAL(j, t, sourceBillId);
	BIND_FROM_TO_NORMAL(j, t, materialId);
	BIND_FROM_TO_NORMAL(j, t, model);
	BIND_FROM_TO_NORMAL(j, t, warehouse);
	BIND_FROM_TO_NORMAL(j, t, unit);

	BIND_FROM_TO_D(j, t, inNum);
	BIND_FROM_TO_D(j, t, inMoney);

	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);




}