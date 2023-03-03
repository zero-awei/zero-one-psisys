#include "stdafx.h"
#include "AddCgrkBillDTO.h"



void from_json(const json& j, AddCgrkBillDTO& t)
{
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_NORMAL(j, t, supplierId);
	BIND_FROM_TO_NORMAL(j, t, invoiceType);


	BIND_FROM_TO_NORMAL(j, t, srcNo);
	BIND_FROM_TO_NORMAL(j, t, subject);
	BIND_FROM_TO_NORMAL(j, t, opDept);
	BIND_FROM_TO_NORMAL(j, t, operator1);
	BIND_FROM_TO_NORMAL(j, t, handler);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, attachment);
	BIND_FROM_TO_I(j, t, hasSwell);

	BIND_FROM_TO_I(j, t, save);

	BIND_FROM_TO_OBJ(j, t, entry, list<CgrkBillEntryDTO>);
	BIND_FROM_TO_OBJ(j, t, files, list<string>);
}