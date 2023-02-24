#pragma once
#ifndef SUPPLIERSNOMALQUERYCONTROLLER_H_
#define SUPPLIERSNOMALQUERYCONTROLLER_H_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/supplierQuery/SuppliersNomalQuery.h"
#include "../../domain/vo/supplierVO/SuppliersInfoVo.h"
#include "api/ApiHelper.h"
#include "domain/vo/PageVO.h"

class SuppliersNomalQueryController
{
public:
	//CREATE_API_FUN_QUERY(querySuppliersNomal, executeQuerySuppliersNomal, SuppliersNomalQuery);
	CREATE_API_FUN_QUERY3(querySuppliersNomal, executeQuerySuppliersNomal);
private:
	JsonVO<PageVO<SuppliersInfoVO>> executeQuerySuppliersNomal();
};


#endif