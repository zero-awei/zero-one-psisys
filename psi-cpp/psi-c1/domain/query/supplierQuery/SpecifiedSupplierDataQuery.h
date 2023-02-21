#pragma once

#ifndef _SPECIFIED_QUERY_
#define _SPECIFIED_QUERY_

#include "../PageQuery.h"

class SpecifiedSupplierDataQuery 
{
	// ±àºÅ
	CC_SYNTHESIZE(string, code, Code);
	
public:
	// °ó¶¨from_json
	friend void from_json(const json& j, SpecifiedSupplierDataQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, code);
	}
};

#endif // !_SPECIFIED_QUERY_
