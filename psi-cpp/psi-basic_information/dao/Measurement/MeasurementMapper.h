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
 * 字段匹配映射
 */
class MeasurementMapper : public Mapper<MeasurementDO>
{
public:
	MeasurementDO mapper(ResultSet* resultSet) const override
	{
		MeasurementDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setSymbol(resultSet->getString(3));
		data.setHas_child(resultSet->getInt(4));
		data.setPid(resultSet->getString(5));
		data.setFactor(resultSet->getDouble(6));
		data.setIs_enabled(resultSet->getInt(7));
		data.setCreate_time(resultSet->getString(8));
		data.setCreate_by(resultSet->getString(9));
		data.setUpdate_time(resultSet->getString(10));
		data.setUpdate_by(resultSet->getString(11));
		return data;
	}
};

/**
 * 列表数据匹配映射
 */
class MeasurementListMapper : public Mapper<MeasurementDO>
{
public:
	MeasurementDO mapper(ResultSet* resultSet) const override
	{
		MeasurementDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setSymbol(resultSet->getString(3));
		data.setHas_child(resultSet->getInt(4));
		data.setFactor(resultSet->getDouble(5));
		data.setIs_enabled(resultSet->getInt(6));
		data.setCreate_time(resultSet->getString(7));
		data.setCreate_by(resultSet->getString(8));
		data.setUpdate_time(resultSet->getString(9));
		data.setUpdate_by(resultSet->getString(10));
		return data;
	}
};

/**
 * pid数据匹配映射
 */
class MeasurementPidMapper : public Mapper<MeasurementDO>
{
public:
	MeasurementDO mapper(ResultSet* resultSet) const override
	{
		MeasurementDO data;
		data.setPid(resultSet->getString(1));
		return data;
	}
};

//导出数据匹配映射
class MeasurementImportMapper : public Mapper<MeasurementDO>
{
public:
	MeasurementDO mapper(ResultSet* resultSet) const override
	{
		MeasurementDO data;
		data.setName(resultSet->getString(1));
		data.setSymbol(resultSet->getString(2));
		data.setHas_child(resultSet->getInt(3));
		data.setPid(resultSet->getString(4));
		data.setFactor(resultSet->getDouble(5));
		data.setIs_enabled(resultSet->getInt(6));
		return data;
	}
};

#endif // !_MESUREMENT_MAPPER_
