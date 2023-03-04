#pragma once
#ifndef _QUERY_CGTHCK_BILL_DETAILED_QUERY_
#define _QUERY_CGTHCK_BILL_DETAILED_QUERY_
#include "../../GlobalInclude.h"

class CgthckBillDetailedDTO {
	// µ¥¾Ý±àºÅ
	CC_SYNTHESIZE(std::string, billNo, BillNo);

public:
	// °ó¶¨from_json
	friend void from_json(const json& j, CgthckBillDetailedDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};





#endif