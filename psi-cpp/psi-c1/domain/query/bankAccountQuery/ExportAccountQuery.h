#pragma once
#ifndef _EXPORTACCOUNTQUERY_H_
#define _EXPORTACCOUNTQUERY_H_
#include "../../GlobalInclude.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/23 16:20:34
*/
class ExportAccountQuery
{
	// id
	CC_SYNTHESIZE(std::string, ids, Ids);
public:
	// Json
	friend void from_json(const json& j, ExportAccountQuery& t) {
		BIND_FROM_TO_OBJ(j, t, ids, std::string);
	}
};

#endif // _EXPORTACCOUNTQUERY_H_