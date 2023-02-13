#pragma once
#ifndef _BASWAREHOUISEITEMQUERY_H_
#define _BASWAREHOUISEITEMQUERY_H_
#include"./PageQuery.h"

class BasWareHouseItemQuery : public PageQuery {

	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, code, Code);
public:
	friend void from_json(const json& j, BasWareHouseItemQuery& f) {
		BIND_FROM_TO_ULL(j, f, pageIndex);
		BIND_FROM_TO_ULL(j, f, pageSize);
		BIND_FROM_TO_NORMAL(j, f, name);
		BIND_FROM_TO_NORMAL(j, f, code);
	}

};
#endif