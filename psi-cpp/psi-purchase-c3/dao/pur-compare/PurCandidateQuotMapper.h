#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/22 13:39:17

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
#ifndef _PUR_CANDIDATE_QUOT_MAPPER_
#define _PUR_CANDIDATE_QUOT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-compare/PurCompareDO.h"

/**
 * 候选报价单字段匹配映射
 */
class PurCandidateQuotMapper : public Mapper<PurCompareDO>
{
public:
	PurCompareDO mapper(ResultSet* resultSet) const override
	{
		PurCompareDO data;
		data.setCandidateQuotIds(resultSet->getString("candidate_quot_ids"));
		return data;
	}
};
#endif


