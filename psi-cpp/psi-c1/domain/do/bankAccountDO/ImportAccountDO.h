#pragma once
#ifndef _IMPORTACCOUNTDO_H_
#define _IMPORTACCOUNTDO_H_
#include "../DoInclude.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:29:45
*/
class ImportAccountDO
{
	CC_SYNTHESIZE(string, code, Code);
	CC_SYNTHESIZE(string, name, Name);
public:
	ImportAccountDO() {
		code = "1";
		name = "1";
	}
};

#endif // _IMPORTACCOUNTDO_H_