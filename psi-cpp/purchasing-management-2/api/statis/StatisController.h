#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/18 10:00:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef __STATIS_CONTROLLER__
#define __STATIS_CONTROLLER__

#include "../../domain/query/StatisQuery/ExeStatusQuery.h"
#include "../../domain/query/StatisQuery/StatisQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/StatisVO/ExeStatusVO.h"
#include "../../domain/vo/StatisVO/StatisVO.h"
#include "../../domain/vo/StatisVO/MaterialVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

#include "../lib-common/include/CharsetConvertHepler.h"


class StatisController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryExeStatus, (execQuery<ExeStatusQuery, ExeStatusVO>), ExeStatusQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryStatis, (execQuery<StatisQuery, StatisVO>), StatisQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryStatisByDept, (execQuery<StatisByDeptQuery, StatisByDeptVO>), StatisByDeptQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryStatisByOperator, (execQuery<StatisByOperatorQuery, StatisByOperatorVO>), StatisByOperatorQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryStatisBySupplier, (execQuery<StatisBySupplierQuery, StatisBySupplierVO>), StatisBySupplierQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryStatisByMaterial, (execQuery<StatisByMaterialQuery, MaterialVO>), StatisByMaterialQuery);

	CREATE_API_FUN_QUERY(exportExeStatus, execExport, ExeStatusQuery);
	CREATE_API_FUN_QUERY(exportStatis, execExport, StatisQuery);
	CREATE_API_FUN_QUERY(exportStatisByDept, execExport, StatisByDeptQuery);
	CREATE_API_FUN_QUERY(exportStatisByOperator, execExport, StatisByOperatorQuery);
	CREATE_API_FUN_QUERY(exportStatisBySupplier, execExport, StatisBySupplierQuery);
	CREATE_API_FUN_QUERY(exportStatisByMaterial, execExport, StatisByMaterialQuery);
private:
	template <class Q, class VO>
	JsonVO<PageVO<VO>> execQuery(const Q& query, const PayloadDTO& payload)
	{
		PageVO<VO> result;
		list<VO> vr;
		vr.push_back(VO());
		vr.push_back(VO());
		result.setRows(vr);
		return JsonVO<PageVO<VO>>(result, RS_SUCCESS);
	}

	template <class E>
	JsonVO<std::string> execExport(const E& query)
	{
		id = E.getId();
		string fileName = CharsetConvertHepler::ansiToUtf8("http://localhost:8090/testExport/" + ".xls");
		return JsonVO<std::string>(fileName, RS_SUCCESS);
	}
};

#endif