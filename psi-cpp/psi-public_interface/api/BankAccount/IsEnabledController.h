#pragma once

#ifndef _ISENABLED_H_
#define _ISENABLED_H_
#include "domain/vo/JsonVO.h"
#include "domain/vo/BankAccountVO/IsEnabledVO.h"
#include "api/ApiHelper.h"

/*
* 是否启用选项
* @Author: Oxygen
* @Date: 2023/2/13 20:49:22
*/
class IsEnabledController
{
public:
	CREATE_API_FUN_QUERY3(queryIsEnabled, executeQueryIsEnabled);
private:
	JsonVO<list<IsEnabledVO>> executeQueryIsEnabled();
};

#endif // _ISENABLED_H_