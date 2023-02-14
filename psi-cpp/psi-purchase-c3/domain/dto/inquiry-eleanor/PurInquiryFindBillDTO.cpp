#include "stdafx.h"
#include "PurInquiryFindBillDTO.h"
void from_json(const json& j, PurInquiryFindBillDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	BIND_FROM_TO_ULL(j, t, purInquiryBillDate);
	BIND_FROM_TO_ULL(j, t, purInquirySubject);
	BIND_FROM_TO_I(j, t, purInquiryIsEffective);
	BIND_FROM_TO_I(j, t, purInquiryIsClosed);
	BIND_FROM_TO_I(j, t, purInquiryIsVoided);
}

