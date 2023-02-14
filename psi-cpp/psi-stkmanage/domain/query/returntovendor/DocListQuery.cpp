#include "stdafx.h"
#include "DocListQuery.h"

void from_json(const json& j, DocListQuery& t)
{
	BIND_FROM_TO_ULL(j, t, pageIndex);
	BIND_FROM_TO_ULL(j, t, pageSize);
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, supplierId);
	BIND_FROM_TO_NORMAL(j, t, billStage);
	BIND_FROM_TO_I(j, t, isEff);
	BIND_FROM_TO_I(j, t, isClosed);
	BIND_FROM_TO_I(j, t, isVoided);
}
