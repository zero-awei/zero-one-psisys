#include "stdafx.h"
#include "EntryPurInquiryDTO.h"

void from_json(const json& j, EntryPurInquiryDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
}

