#include "stdafx.h"
#include "CgrkBillEntryDTO.h"



void from_json(const json& j, CgrkBillEntryDTO& t)
{

	BIND_FROM_TO_NORMAL(j, t, batchNo);
	BIND_FROM_TO_NORMAL(j, t, billNo);
	BIND_FROM_TO_D(j, t, cost);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, custom2);
	BIND_FROM_TO_D(j, t, discountRate);
	BIND_FROM_TO_I(j, t, entryNo);
	BIND_FROM_TO_D(j, t, expense);
	BIND_FROM_TO_NORMAL(j, t, id);
	BIND_FROM_TO_D(j, t, invoicedAmt);
	BIND_FROM_TO_D(j, t, invoicedQty);
	BIND_FROM_TO_NORMAL(j, t, materialId);
	BIND_FROM_TO_NORMAL(j, t, mid);
	BIND_FROM_TO_D(j, t, price);
	BIND_FROM_TO_D(j, t, qty);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_D(j, t, settleAmt);
	BIND_FROM_TO_D(j, t, settleQty);
	BIND_FROM_TO_NORMAL(j, t, srcBillId);
	BIND_FROM_TO_NORMAL(j, t, srcBillType);
	BIND_FROM_TO_NORMAL(j, t, srcEntryId);
	BIND_FROM_TO_NORMAL(j, t, srcNo);
	BIND_FROM_TO_NORMAL(j, t, stockIoDirection);
	BIND_FROM_TO_NORMAL(j, t, supplierId);
	BIND_FROM_TO_D(j, t, swellQty);
	BIND_FROM_TO_D(j, t, tax);
	BIND_FROM_TO_D(j, t, taxRate);
	BIND_FROM_TO_NORMAL(j, t, unitId);
	BIND_FROM_TO_NORMAL(j, t, version);
	BIND_FROM_TO_NORMAL(j, t, warehouseId);
	
}