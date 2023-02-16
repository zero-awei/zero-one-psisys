#pragma once


/*
@Author: qiuqiu
@Date: 2023/2/13
*/

#ifndef SUPPLIERSNAMECONTROLLER_H_
#define SUPPLIERSNAMECONTROLLER_H_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/supplierVO/SuppliersNameVO.h"
#include "api/ApiHelper.h"

class SuppliersNameController
{
public:
	CREATE_API_FUN_QUERY3(querySuppliersName, executeQuerySuppliersName);
private:
	JsonVO<std::list<SuppliersName>> executeQuerySuppliersName();
};


#endif