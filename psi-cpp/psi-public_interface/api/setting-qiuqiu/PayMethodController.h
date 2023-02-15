#pragma once
/*
@Author: qiuqiu
@Date: 2023/2/14
*/

#ifndef PAYMETHODCONTROLLER_H_
#define PAYMETHODCONTROLLER_H_

#include "domain/vo/JsonVO.h"
#include "domain/vo/qiuqiu/PayMethodTypeVO.h"
#include "api/ApiHelper.h"

class PayMethodController
{
public:
	CREATE_API_FUN_QUERY3(queryPayMethod, executeQueryPayMethod);
private:
	JsonVO<std::list<PayMethodType>> executeQueryPayMethod();
};



#endif // !PAYMETHODCONTROLLER_H_
