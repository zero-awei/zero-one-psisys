#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/14 21:30:00

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
#include "../../domain/vo/StatisVO/StatisVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


class StatisController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryExeStatus, execQuerySample, ExeStatusQuery);
private:
	JsonVO<PageVO<StatisVO>> execQuerySample(const ExeStatusQuery& query, const PayloadDTO& payload)
	{
		PageVO<StatisVO> result;
		return JsonVO<PageVO<StatisVO>>(result, RS_SUCCESS);
	}
};

#endif
