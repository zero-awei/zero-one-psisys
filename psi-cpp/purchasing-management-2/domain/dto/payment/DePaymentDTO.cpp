
#include "stdafx.h"
#include "DePaymentDTO.h"

void from_json(const json& j, DePaymentDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, bill_no);
}