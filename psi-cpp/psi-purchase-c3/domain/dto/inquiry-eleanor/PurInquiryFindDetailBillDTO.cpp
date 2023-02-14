#include "stdafx.h"
#include "PurInquiryFindDetailBillDTO.h"

void from_json(const json& j, PurInquiryFindDetailBillDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
}