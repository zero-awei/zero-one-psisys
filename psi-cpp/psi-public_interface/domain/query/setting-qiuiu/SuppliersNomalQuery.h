#pragma once
/*
@Author: qiuqiu
@Date: 2023/2/13
*/

#ifndef SUPPLIERSNOMALQUERY_H_
#define SUPPLIERSNOMALQUERY_H_

#include "../PageQuery.h"

class SuppliersNomalQuery : public PageQuery
{
	CC_SYNTHESIZE(std::string, id, ID);
	CC_SYNTHESIZE(std::string, code, Code);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, auxname, AuxName);
	CC_SYNTHESIZE(std::string, create_time, Create_Time);
public:
	// °ó¶¨from_json
	friend void from_json(const json& j, SuppliersNomalQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, auxname);
		BIND_FROM_TO_NORMAL(j, t, create_time);
	}
};



#endif // !SUPPLIERSNOMALQUERY_H_

