#include "stdafx.h"
#include "ModifyDocListDTO.h"

void from_json(const json& j, ModifyDocListDTO& t)
{
	BIND_FROM_TO_NORMAL(j, t, srcNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_D(j, t, settleQty);
	BIND_FROM_TO_D(j, t, tax);
	BIND_FROM_TO_D(j, t, settleAmt);
	BIND_FROM_TO_D(j, t, cost);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
}
