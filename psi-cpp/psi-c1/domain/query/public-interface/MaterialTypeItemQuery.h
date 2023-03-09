#pragma once
#ifndef _MATERIALTYPEITEMQUERY_H_
#define _MATERIALTYPEITEMQUERY_H_
#include"../PageQuery.h"
/*
	@Author: kiva
 @Date: 2023/2/13 15:36
*/

class MaterialTypeItemQuery :public PageQuery{
	
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, code, Code);

public:
	friend void from_json(const json& j, MaterialTypeItemQuery& f) {
		BIND_FROM_TO_ULL(j, f, pageIndex);
		BIND_FROM_TO_ULL(j, f, pageSize);
		BIND_FROM_TO_NORMAL(j, f, name);
		BIND_FROM_TO_NORMAL(j, f, code);
	}
};


#endif