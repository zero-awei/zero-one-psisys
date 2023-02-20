#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _MEASUREMENT_MAPPER_
#define _MEASUREMENT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Measurement/MeasurementDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class MeasurementMapper : public Mapper<MeasurementDO>
{
public:
	MeasurementDO mapper(ResultSet* resultSet) const override
	{
		MeasurementDO data;
		return data;
	}
};

#endif // !_MESUREMENT_MAPPER_
