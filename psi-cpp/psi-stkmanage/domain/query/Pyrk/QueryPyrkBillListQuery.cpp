#include "stdafx.h"
#include "QueryPyrkBillListQuery.h"

void from_json(const json& j, QueryPyrkBillListQuery& t)
{
	BIND_FROM_TO_ULL(j, t, pageIndex);
	BIND_FROM_TO_ULL(j, t, pageSize);
	BIND_FROM_TO_NORMAL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, beginData);
	BIND_FROM_TO_NORMAL(j, t, endData);
	BIND_FROM_TO_NORMAL(j, t, theme);
	BIND_FROM_TO_I(j, t, stage);
	BIND_FROM_TO_I(j, t, isEffective);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);
}